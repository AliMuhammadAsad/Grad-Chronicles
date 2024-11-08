function [f, F_x, F_u] = transitionFunction(x,u, b)
% [f, F_x, F_u] = transitionFunction(x,u,b) predicts the state x at time t given
% the state at time t-1 and the input u at time t. F_x denotes the Jacobian
% of the state transition function with respect to the state evaluated at
% the state and input provided. F_u denotes the Jacobian of the state
% transition function with respect to the input evaluated at the state and
% input provided.
% State and input are defined according to "Introduction to Autonomous Mobile Robots", pp. 337

%STARTRM
f = x + [ ...
    (u(1)+u(2))/2 * cos(x(3) + (u(2)-u(1))/(2*b) )
    (u(1)+u(2))/2 * sin(x(3) + (u(2)-u(1))/(2*b) )
    (u(2)-u(1))/b ...
    ];

F_x = [...
    1, 0, -sin(x(3) - (u(1) - u(2))/(2*b))*(u(1)/2 + u(2)/2)
    0, 1,  cos(x(3) - (u(1) - u(2))/(2*b))*(u(1)/2 + u(2)/2)
    0, 0,  1 ...
    ];

F_u = [...
    cos(x(3) - (u(1) - u(2))/(2*b))/2 + (sin(x(3) - (u(1) - u(2))/(2*b))*(u(1)/2 + u(2)/2))/(2*b), cos(x(3) - (u(1) - u(2))/(2*b))/2 - (sin(x(3) - (u(1) - u(2))/(2*b))*(u(1)/2 + u(2)/2))/(2*b)
    sin(x(3) - (u(1) - u(2))/(2*b))/2 - (cos(x(3) - (u(1) - u(2))/(2*b))*(u(1)/2 + u(2)/2))/(2*b), sin(x(3) - (u(1) - u(2))/(2*b))/2 + (cos(x(3) - (u(1) - u(2))/(2*b))*(u(1)/2 + u(2)/2))/(2*b)
    -1/b,                                                                                          1/b ...
    ];
%ENDRM

%STARTUNCOMMENT
% f = TODO
% F_x = TODO
% F_u = TODO
%ENDUNCOMMENT