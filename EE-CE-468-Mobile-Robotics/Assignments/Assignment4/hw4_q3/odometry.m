function [x_bar, Fx, Fu] = odometry(x, u, b)
    theta = x(3,1);
    x_bar = zeros(3,1);
    x_bar(1,1) = x(1,1) + (u(1,1) + u(2,1))/2 * cos(theta);
    x_bar(2,1) = x(2,1) + (u(1,1) + u(2,1))/2 * sin(theta);
    x_bar(3,1) = x(3,1) + (-u(1,1) + u(2,1))/b;
    Fx = [
        1 0 -sin(theta);
        0 1 cos(theta);
        0 0 1
        ];
    Fu = [
        cos(theta)/2 cos(theta)/2;
        sin(theta)/2 sin(theta)/2;
        -1/b 1/b
        ];

end