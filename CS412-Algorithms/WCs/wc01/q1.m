n = 1:1000; % range of n

% Define the function f(n)
f = 2*n.^2 + 3*n + 1;
c_values = [6, 3.75, 28/9, 2.8125, 2.64, 2]; % Example c values from the table provided in the question

% Plot f(n)
figure;
plot(n, f, 'b', 'LineWidth', 2);
hold on;

for i = 1:length(c_values)
    c = c_values(i);     cg = c * n.^2;
    plot(n, cg, 'LineWidth', 1.5);
    text(n(end), cg(end), ['c = ' num2str(c)], 'HorizontalAlignment', 'left');
end

% Labels
xlabel('n'); ylabel('Function values');
title('Comparison of f(n) and c*g(n) for various c');
grid on; hold off;
