function [new_particles, SIGMA_posterori] = mclIncrementalLocalization(particles, SIGMA_seq, u, Q, S, M, params, g, b

C_TR = diag([repmat(0.01^2, 1, size(S, 2)) repmat(0.01^2, 1, size(S, 2))]);

[Z, R, ~] = extractLinesPolar(S(1,:), S(2,:), C_TR, params);

% Estimate robot pose
[new_particles, SIGMA_posterori] = mclStep(particles, SIGMA_seq, Z, Q, R,u,b,M,g);


