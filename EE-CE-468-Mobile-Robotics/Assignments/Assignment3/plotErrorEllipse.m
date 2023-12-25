function plotErrorEllipse(mu, Sigma, p)

    s = -2 * log(1 - p);

    [V, D] = eig(Sigma * s);

    t = linspace(0, 2 * pi);
    a = (V * sqrt(D)) * [cos(t(:))'; sin(t(:))'];
    plot(a(1, :) + mu(1), a(2, :) + mu(2));
end

% function plotErrorEllipse(mu, Sigma, p)
% 
%     s = -2 * log(1 - p);
% 
%     [V, D] = eig(Sigma * s);
% 
%     t = linspace(0, 2 * pi);
%     a = (V * sqrt(D)) * [cos(t(:))'; sin(t(:))'];
% 
%     % Extend for the third dimension
%     a = [a; zeros(1, numel(t))];
% 
%     % Plot the error ellipse
%     plot3(a(1, :) + mu(1), a(2, :) + mu(2), a(3, :) + mu(3));
% 
%     % Adjust plot properties as needed
%     xlabel('X');
%     ylabel('Y');
%     zlabel('Theta');
%     grid on;
%     axis equal;
%     title('Error Ellipse');
% end
