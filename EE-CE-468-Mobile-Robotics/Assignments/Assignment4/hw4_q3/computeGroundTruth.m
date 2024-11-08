function groundTruthState = computeGroundTruth(robotpose, left, right, sampleTime)
%computeWheelVelocities computes wheel velocity based on rate of change of
%the yaw angle of the wheel relative to its original mount on the robot
%body

persistent initAngles

% compute rotation between wheel original mount on the robot body and world
% frame
robotRtom = quat2rotm([robotpose.Orientation.W, robotpose.Orientation.X, robotpose.Orientation.Y, robotpose.Orientation.Z]);
originalWheelMount = robotRtom*eul2rotm([pi/2 pi/2 0]);

% get rotation between wheel and the world frame
leftRtom = quat2rotm([left.Orientation.W, left.Orientation.X, left.Orientation.Y, left.Orientation.Z]);
rightRtom = quat2rotm([right.Orientation.W, right.Orientation.X, right.Orientation.Y, right.Orientation.Z]);

% compute relative rotation between wheel and its original mount
leftRotation = rotm2eul(originalWheelMount'*leftRtom);
rightRotation = rotm2eul(originalWheelMount'*rightRtom);

% compute angluar velocity using the angle difference between the current
% angle pose and the the angle pose in last time step
angles = [leftRotation(1); rightRotation(1)];
if isempty(initAngles)
    initAngles = angles;
end
omegas = angdiff(initAngles, angles)/sampleTime;
%omegas = (wrapTo2Pi(angles)-wrapTo2Pi(initAngles))/sampleTime;
initAngles = angles;

% Compute Pose
rot = quat2eul([robotpose.Orientation.W, robotpose.Orientation.X, robotpose.Orientation.Y, robotpose.Orientation.Z]);
x = robotpose.Position.X;
y = robotpose.Position.Y;
yaw = rot(1);
groundTruthState = [x;y;yaw;omegas];
global odom;
odom = [odom [angles;sampleTime]];
