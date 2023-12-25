function [Xpri, F_x, F_u] = transitionFunction(x, u, b)
    theta = x(3,1);
    Xpri = zeros(3,1);
    Xpri(1,1) = x(1,1) + (u(1,1) + u(2,1))/2 * cos(theta);
    Xpri(2,1) = x(2,1) + (u(1,1) + u(2,1))/2 * sin(theta);
    Xpri(3,1) = x(3,1) + (-u(1,1) + u(2,1))/b;
    F_x = [
        1 0 -sin(theta);
        0 1 cos(theta);
        0 0 1
        ];
    F_u = [
        cos(theta)/2 cos(theta)/2;
        sin(theta)/2 sin(theta)/2;
        -1/b 1/b
        ];

end