x = [5 6 3.4000 2.7000 10 9.7000 9.5500 3.0500 8.1500 6.2000 2.9000 6.3500 4.6000 5.8000 7.4000 3.6000 7.8500 8.8000 7 5.4500 9.1000 10.2000 4.1000 3.9500 2.4500];
y = [1.5820 1.8220 1.0570 0.5000 2.2360 2.3860 2.2940 0.5580 2.1660 1.8660 0.6530 1.9300 1.5620 1.7370 2.0880 1.1370 2.1790 2.1120 1.8000 1.5010 2.3030 2.3100 1.1940 1.1440 0.1230];
X = [ones(size(x)); x; x.^2]';
b = X\y';
plot(x, y, 'o');
hold on;
x_fit = linspace(min(x), max(x), 100); 
y_fit = b(1) + b(2)*x_fit + b(3)*x_fit.^2; 
plot(x_fit, y_fit, '-'); 
hold off; xlabel('X'); ylabel('Y'); title('Y vs x');
yhat = b(1) + b(2)*x + b(3)*x.^2;
error = yhat - y;
scatter(x, error); xlabel('x'); ylabel('Error'); title('Cluster - Error vs x');
figure;
hist(error, 20);
xlabel('Error'); ylabel('Frequency'); title('Histogram - Errors for Quadratic Model');

z = 1 ./ x;
figure; % Create a new figure
plot(z, y, 'o'); % 'o' creates a scatter plot with circle markers
title('Cluster - Y vs. Z'); xlabel('Z (1/X)'); ylabel('Y');
Z = [ones(size(z)); z]';
coeffs = Z \ y';
a_0 = coeffs(1); a_1 = coeffs(2);
yb = a_0 + a_1*z;
error = y - yb;
scatter(z, error); xlabel('Z'); ylabel('Error'); title('Error Against Z');
hist(error, 20); % Adjust the number of bins (20 here is arbitrary)
xlabel('Error'); ylabel('Frequency'); title('Histogram of Error for Intrinsically Linear Model');


x = [7.0175 4.1186 2.6674];
y = [1.9609 1.3025 0.3578];
X = [ones(size(x)); x; x.^2]';
b = X\y';
b0 = b(1); b1 = b(2); b2 = b(3);
yb = b0 + b1.*x + b1.*(x.^2);
error = y - yb;
z = 1 ./ x;
Z = [ones(size(z)); z]';
coeffs = Z \ y';
a_0 = coeffs(1); a_1 = coeffs(2);
yb_i = a_0 + a_1*z;
error_i = y - yb_i;
abs_error = abs(error); abs_error_i = abs(error_i);
sum_error = sum(abs_error); sum_error_i = sum(abs_error_i);


