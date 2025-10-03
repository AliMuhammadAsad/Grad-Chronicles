function [ref_poses] = generateWaypoints(pathType)
%   The function generates waypoints for different path types.


switch lower(pathType)
    case 'circle'
        waypoint_sep = 0.1;
        radius = 2.5;
        center = [radius, 0];
        num_points = floor(2*pi*radius/waypoint_sep);
        theta = (pi:-2*pi/num_points:-pi)';
        ref_poses = [radius*cos(theta)+center(1), radius*sin(theta)+center(2), theta-pi/2];
    case 'wave'
        x = (0:0.2:20)';
        y = sin(x);
        theta = atan2(cos(x),1);
        ref_poses = [x,y,theta];
end

end