function [x_posterori, P_posterori, Xpri] = incrementalLocalization(x, P, u, Q, S, M, params, g, b)
% [x_posterori, P_posterori, Xpri] = incrementalLocalization(x, P, u, S, R, M,
% k, b, g) returns the a posterori estimate of the state and its covariance,
% given the previous state estimate, control inputs, laser measurements and
% the map
% Here, we have:
% x = State Vector = [x, y, theta]
% P = Covariance Matrix associated with the state. \Sigma
% u = Control Commands = [vL*Ts; vR*Ts]
% Q = Covariance Matrix of noise associated with the motion model.m
% S = [Theta, Rou] Readings from Lidar
% M = map consisting of slope and intercept of each line (wall)
% params = Some constants such as D, L, etc.
% g = gating threshold
% b = L


% This is covariance matrix representing lidar noise with dimensions
% determined by the size of the matrix S. The diagonal elements of the
% matrix are set to the square of standard deviation in lidar, indicating
% that the diagonal elements represent the variance of some random
% variable.
C_TR = diag([repmat(0.01^2, 1, size(S, 2)) repmat(0.01^2, 1, size(S, 2))]);

% Function that takes a set of polar coordinates, a covariance matrix, and
% some parameters, and returns the corresponding measurements and
% measurement noise covariance matrix. Since there are multiple
% measurements, there will be a 2x2 R for each vector of measurements.

[z, R, ~] = extractLinesPolar(S(1,:), S(2,:), C_TR, params);

% Estimate robot pose
[x_posterori, P_posterori, Xpri] = filterStep(x, P, u, Q, z, R, M, g, b);

