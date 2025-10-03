function [x_posteriori, P_posteriori] = filterStep(x, P, u, Z, R, M, k, g, b)
% [x_posteriori, P_posteriori] = filterStep(x, P, u, z, R, M, k, g, b)
% returns an a posteriori estimate of the state and its covariance

%STARTUNCOMMENT
% % additional bells and whistles in case no line was detected, please
% % incorporate this at a sensical position in your code
% if size(Z,2) == 0
%     x_posteriori = x_priori;
%     P_posteriori = P_priori;
%     return;
% end
% x_posteriori = TODO
% P_posteriori = TODO
%ENDUNCOMMENT

%STARTRM

% propagate the state (p. 337)
Q = k*diag(abs(u));

[x_priori, F_x, F_u] = transitionFunction(x, u, b);
P_priori = F_x * P * F_x' + F_u * Q * F_u';

if size(Z,2) == 0
    x_posteriori = x_priori;
    P_posteriori = P_priori;
    return;
end
    
[v, H, R] = associateMeasurements(x_priori, P_priori, Z, R, M, g);

y = reshape(v, [], 1);
H = reshape(permute(H, [1,3,2]), [], 3);
R = blockDiagonal(R);

% update state estimates (pp. 335)
S = H * P_priori * H' + R;
% K = P_priori * H' * inv(S);
K = P_priori * (H' / S);

% P_posteriori = P_priori - K * S * K';
P_posteriori = (eye(size(P_priori)) - K*H) * P_priori;
x_posteriori = x_priori + K * y;

%ENDRM
