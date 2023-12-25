function [x_posterori, P_posterori] = incrementalLocalization(x, P, u, S, M, params, k, g, b)
% [x_posterori, P_posterori] = incrementalLocalization(x, P, u, S, R, M,
% k, b, g) returns the a posterori estimate of the state and its covariance,
% given the previous state estimate, control inputs, laser measurements and
% the map

C_TR = diag([repmat(0.1^2, 1, size(S, 2)) repmat(0.1^2, 1, size(S, 2))]);


%STARTRM
[z, R, ~] = extractLinesPolar(S(1,:), S(2,:), C_TR, params);

%R = repmat(eye(2) * 0.001, [1, 1, size(z, 2)]);

figure(2), cla, hold on;
z_prior = zeros(size(M));
for k = 1:size(M,2)
    z_prior(:,k) = measurementFunction(x, M(:,k));
end
plot(z(1,:), z(2,:),'bo');
plot(z_prior(1,:), z_prior(2,:),'rx');
%     plot(M(1,:), M(2,:),'go');
xlabel('angle [rad]'); ylabel('distance [m]')
legend('measurement','prior')
drawnow

% R = repmat(.01*eye(2), [1, 1, size(z,2)]);

% estimate robot pose
[x_posterori, P_posterori] = filterStep(x, P, u, z, R, M, k, g, b);

%ENDRM

%STARTUNCOMMENT
% [x_posterori, P_posterori] = TODO
%ENDUNCOMMENT