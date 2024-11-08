% This code has been created by making use of the following resources:
% 1. Mathworks example of obstacle avoidance using VFH for turtlebot 
% https://www.mathworks.com/help/nav/ug/obstacle-avoidance-with-turtlebot-and-vfh.html
% 2. Code files from the case-study based problem assigned by Prof.
% Siegwart in his AMR class at ETH. 
clc;
clear;
clear computeGroundTruth;
global odom;
odom = [];

% Set paramter values
params.MIN_SEG_LENGTH = 0.01;
params.LINE_POINT_DIST_THRESHOLD = 0.005;
params.MIN_POINTS_PER_SEGMENT = 20;
params.WHEEL_SEP = 0.16; % L
params.WHEEL_DIA = 0.066; % D = R/2

% Connect to the TurtleBot using the IP address obtained from setup.
% Add your respective Linux IP here. 
rosinit("192.168.128.128",11311);

% The subscriber receives the laser scan data from the robot. The publisher
% sends velocity commands to the robot. Gazebo doesn't have a built-in
% encoder, so it will be created later. 
laserSub = rossubscriber("/scan","DataFormat","struct");
[velPub, velMsg] = rospublisher("/cmd_vel","DataFormat","struct");

% Subscribe to Gazebo to recieve groundtruth robot pose and wheel angles to
% compute wheel displacements and emulate wheel encoders. We'll compare our
% localized pose to the ground truth.
linksub = rossubscriber('gazebo/link_states');

% Load a map of the environment. Each column in the loaded matrix are
% parameters (angle and distance) for a line/wall in the environment. 
load('M.mat');
%%%%%%%%%%%%%%%% The limits %%%%%%%%%%


% Set initial Pose. We're certain about our starting point.
x = zeros(3,1);
P = diag([0.0001; 0.0001; 0.0001]);
%%%%%% Might not need the below%%%%%%%%
xhat = x;
xhat_seq = x;
xbar_seq =x;
xTruth = x;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
particles = MCL_initializeParticles(numParticles);
weights = ones(numParticles, 1) / numParticles; % Uniform initial weights



% Set up VFH object for obstacle avoidance. Set the UseLidarScan property
% to true. Specify algorithm properties for robot specifications. Set
% target direction to 0 in order to drive straight.
vfh = controllerVFH;
vfh.UseLidarScan = true;
vfh.DistanceLimits = [0.05 1];
vfh.RobotRadius = 0.1;
vfh.MinTurningRadius = 0.2;
vfh.SafetyDistance = 0.1;

targetDir = 0;

% Set up a Rate object using rateControl, which can track the timing of
% your loop.
rate = rateControl(10);

% Use the ROS subscriber to collect laser scan data. Calculate the steering
% direction with the VFH object based on the input laser scan data. Convert
% the steering direction to a desired linear and an angular velocity. If a
% steering direction is not found, the robot stops and searches by rotating
% in place. Drive the robot by sending a message containing the angular
% velocity and the desired linear velocity using the ROS publisher.
prevTime = 1;
while rate.TotalElapsedTime < 30

	% Get laser scan data and create a lidarScan object
	scanMsg = receive(laserSub);
    scan = rosReadLidarScan(scanMsg);
    [cart,~]=rosReadCartesian(scanMsg);

    % Receive ground truth data
    gazeboLinksPoses = receive(linksub);
    currTime = rostime("now");
    sampleTime = currTime - prevTime;
    sampleTime = sampleTime.Nsec*1e-9;
    prevTime = currTime;    
	
    % Call VFH object to computer steering direction
	steerDir = vfh(scan,targetDir);  
    
	% Calculate velocities commands
	if ~isnan(steerDir) % If steering direction is valid
		desiredV = 0.2;
		desiredw = exampleHelperComputeAngularVelocity(steerDir,.5);
	else % Stop and search for valid direction
		desiredV = 0.0;
		desiredw = 0.5;
    end

	% Assign and send velocity commands
	velMsg.Linear.X = desiredV;
	velMsg.Angular.Z = desiredw;
	velPub.send(velMsg);

    % Compute ground truth data from received information
    indices = zeros(3,1);
    for i = 1:size(gazeboLinksPoses.Pose)
        if strcmp(gazeboLinksPoses.Name(i), 'turtlebot3_burger::base_footprint')
            indices(1) = i;
        elseif strcmp(gazeboLinksPoses.Name(i), 'turtlebot3_burger::wheel_left_link')
            indices(2) = i;
        elseif strcmp(gazeboLinksPoses.Name(i), 'turtlebot3_burger::wheel_right_link')
            indices(3) = i;            
        end  
    end
    groundTruth = computeGroundTruth(gazeboLinksPoses.Pose(indices(1)),gazeboLinksPoses.Pose(indices(2)),gazeboLinksPoses.Pose(indices(3)),sampleTime);

    % Compute linear and angular velocities from robot wheel velocities
    v = (groundTruth(4) + groundTruth(5))*params.WHEEL_DIA/4; % v = (wl + wr)* d /4
    w = (groundTruth(5) - groundTruth(4))*params.WHEEL_DIA/(2*params.WHEEL_SEP);
    % Compute odometry and store the ground truth.
    x = [x, ...
        [x(1,end)+v*sampleTime*cos(x(3,end));
         x(2,end)+v*sampleTime*sin(x(3,end)); 
         x(3,end)+w*sampleTime]
         ];    
    xTruth = [xTruth, groundTruth(1:3,1)];
    
    u = ([groundTruth(4); groundTruth(5)] ) * sampleTime * params.WHEEL_DIA/2;
    Q = eye(2)*.000001;
    
    % Extract lines
    cart(:,1) = cart(:,1)-0.032;    
    [theta,rho] = cart2pol(cart(:,1),cart(:,2));
    [xhat, P, xpri] = incrementalLocalization(xhat, P, u, Q, [theta'; rho'], M, params, sqrt(10), params.WHEEL_SEP);
    xhat_seq = [xhat_seq, xhat];
    xbar_seq = [xbar_seq, xpri];
    waitfor(rate);
end

% Disconnect from the ROS network
rosshutdown;

% Plotting data
figure;
plot(xTruth(1,:),xTruth(2,:),'k.');
hold on;
plot(x(1,:),x(2,:),'b.');
% plot(xbar_seq(1,:),xbar_seq(2,:),'g.');
plot(xhat_seq(1,:),xhat_seq(2,:),'r.');
legend('Ground Truth','Odemetry ','Estimated X');

