function w = exampleHelperComputeAngularVelocity(steeringDir, wMax)
%EXAMPLEHELPERCOMPUTEANGULARVELOCITY Compute angular velocity
%   W = exampleHelperComputeAngularVelocity(STEERINGDIR)
%   returns the angular velocity W for a differential drive robot in radians
%   per second for a given steering direction STEERINGDIR in the robot's
%   coordinate frame in radians.
%
%   W = exampleHelperComputeAngularVelocity(STEERINGDIR, WMAX)
%   returns the angular velocity W for a differential drive robot in radians
%   per second for a given steering direction STEERINGDIR in the robot's
%   coordinate frame in radians and maximum angular velocity WMAX in
%   radians per second. The output angular velocity is saturated based on
%   the WMAX.
%
%   Example:
%       
%       w = exampleHelperComputeAngularVelocity(0.2, 1);

% Copyright 2015 The MathWorks, Inc.

%#codegen
%#ok<*EMCA>

% Allow variable input arguments
if nargin == 1   
    wMax = inf;
end

validateattributes(steeringDir, {'double'},{'real'},...
    'exampleHelperComputeAngularVelocity', 'STEERINGDIR', 1);
validateattributes(wMax, {'double'},{'real', 'positive'},...
    'exampleHelperComputeAngularVelocity', 'WMAX', 2);

% Computing in robot's coordinate frame
curPose = [0 0 0];

% The following computation is similar to robotics.PurePursuit
lookaheadPoint = [cos(steeringDir), sin(steeringDir)];
slope = atan2((lookaheadPoint(2) - curPose(2)), ...
    (lookaheadPoint(1) - curPose(1)));
alpha = angdiff(curPose(3), slope);

% Angular velocity command for a differential drive robot is
% equal to the desired curvature to be followed by the robot.

w = (2*sin(alpha));

% Pick a constant rotation when robot is facing in the opposite
% direction of the path
if abs(abs(alpha) - pi) < 1e-12
    w = sign(w)*1;
end

if abs(w) > wMax
    w = sign(w)*wMax;
end

end

