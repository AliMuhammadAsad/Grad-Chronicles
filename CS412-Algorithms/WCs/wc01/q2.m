n = 1:1000000;  % Adjust as needed for 'large values' of n

% Calculate logarithms with different bases
log2_n = log2(n);  % Base 2
log7_n = log(n) / log(7);  % Change of base to 7
log10_n = log10(n);  % Base 10
log100_n = log(n) / log(100);  % Change of base to 100

% Plot the logarithm functions
figure;
plot(n, log2_n, 'b', 'LineWidth', 2);
hold on;
plot(n, log7_n, 'r', 'LineWidth', 2);
plot(n, log10_n, 'g', 'LineWidth', 2);
plot(n, log100_n, 'k', 'LineWidth', 2);

% Labels and legend
xlabel('n'); ylabel('log(n)');
title('Logarithm functions with different bases');
legend('Base 2', 'Base 7', 'Base 10', 'Base 100');
grid on; hold off;