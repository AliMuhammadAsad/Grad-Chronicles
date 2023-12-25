function [h, H_x] = measurementFunction(x, m)
% [h, H_x] = measurementFunction(x, m) returns the predicted measurement
% given a state x and a single map entry m. H_x denotes the Jacobian of the
% measurement function with respect to the state evaluated at the state
% provided.
% Map entry and state are defined according to "Introduction to Autonomous Mobile Robots" pp. 337

% m21 = m(2,1)
% m11 = m(1,1)
% x11 = x(1,1)
% x21 = x(2,1)

h = [
    angdiff(x(3,1), m(1,1));
    m(2,1) - ( x(1,1)*cos(m(1,1)) + x(2,1)*sin(m(1,1)));
    ];
H_x = [
    0 0 -1;
    -cos(m(1,1)) -sin(m(1,1)) 0
    ];


[h(1), h(2), isRNegated] = normalizeLineParameters(h(1), h(2));

if isRNegated 
    H_x(2, :) = - H_x(2, :);
end

