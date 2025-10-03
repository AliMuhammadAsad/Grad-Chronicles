y = [25.9000 29.5000 27.9000 25.9000 29.9000 29.9000 30.9000 28.9000 35.9000 31.5000 31 30.9000 30 36.9000 41.9000 40.5000 43.9000 37.5000 37.9000 44.5000 37.9000 38.9000 36.9000 45.8000];
x = [4.9176 5.0208 4.5429 4.5573 5.0597 3.8910 5.8980 5.6039 5.8282 5.3003 6.2712 5.9592 5.0500 8.2464 6.6969 7.7841 9.0384 5.9894 7.5422 8.7951 6.0831 8.3607 8.1400 9.1416];

a = 0.05;

sx = sum(x); sy = sum(y); x2 = x.^2; y2 = y.^2; sx2 = sum(x2); sy2 = sum(y2); xy = x.*y; sxy = sum(xy);
n = length(x);

ssxy = sxy - ((1/n) * sx * sy); ssxx = sx2 - ((1/n) * (sx)^2);
b1 = ssxy / ssxx;
b0 = (1/n)*sy - (b1 * ((1/n) * sx));

% num = sxy - (1/n)*(sx*sy);
% denom = sqrt((sx2 - (1/n)*(sx^2))*(sy2 - (1/n)*(sy^2)));
% r = num / denom;

y_pred = b0 + b1 * x;
res = y - y_pred;
res2 = res.^2;
sum_res = sum(res);
SSE = sum(res2);
se = sqrt(SSE / (n - 2));
ssyy = sy2 - ((1/n) * (sy)^2);
r2 = ((b1^2) * ssxx) / ssyy;
sb = se / sqrt(ssxx);
t_val = (b1 - 0) / sb;
t = tinv(1 - a/2, n - 2); 
x0 = 8.0;
y_ht = b0 + b1*x0;
x_bar = mean(x);

ci_b1 = y_ht + [-1 1]*t*se*sqrt((1/n) + ((x0 - x_bar).^2/ssxx));
pi_b1 = y_ht + [-1 1]*t*se*sqrt(1 + (1/n) + ((x0 - x_bar).^2/ssxx));

%Plotting
figure; 

%Observed Data and Regression Line
subplot(3, 2, 1);
scatter(x, y); xlabel('x'); ylabel('y'); title('Scatter Plot');
normplot(res);
hold on;
x_fit = min(x):max(x); y_fit = b0 + b1*x_fit;
plot(x_fit, y_fit, '-r', 'DisplayName', 'Regression Line');
xlabel('x'); ylabel('y'); title('Observed Data and Regression Line');
legend('Location', 'best'); grid on; hold off;

%Residual vs Order
subplot(3, 2, 2);
plot(1:length(res), res, 'o-', 'DisplayName', 'Residuals');
xlabel('Order'); ylabel('Residuals'); title('Residuals vs Orders');
grid on; legend('Location', 'best');

%Histogram of Residuals
subplot(3, 2, 3);
histogram(res, 10, 'EdgeColor', 'black', 'FaceColor', 'blue', 'DisplayName', 'Residuals');
xlabel('Residuals'); ylabel('Frequency'); title('Histogram of Residuals'); grid on; legend('Location', 'best');

%Fitted Value vs Residuals
subplot(3, 2, 4);
plot(y_pred, res, 'o', 'DisplayName', 'Fitted Value vs Residual');
xlabel('Fitted Value'); ylabel('Residuals'); title('Fitted Value vs Residuals'); grid on; legend('Location', 'best');


