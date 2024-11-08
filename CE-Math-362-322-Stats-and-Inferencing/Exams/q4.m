data = [40  30	55	45;
65	50	80	65;
60	60	60	60;
30	40	55	55;
50	40	65	60;
30	30	50	50;
60	30	60	55;
70	70	70	NaN;
65	60  NaN NaN;		
35  NaN NaN NaN;];

anova1(data);
ns = sum(~isnan(data)); gms = mean(data, 1, 'omitnan');
q = 3.845;
MSE = 163.768;
n1 = ns(1); n2 = ns(2); n3 = ns(3); n4 = ns(4);

fprintf("Groups: \t Critical \t Actual\n")

fprintf('1 and 2:        %f \t %f\n',q*sqrt((MSE / 2)*((1/n1)+(1/n2))), gms(1) - gms(2));
fprintf('1 and 3:        %f \t%f\n',q*sqrt((MSE / 2)*((1/n1)+(1/n3))), gms(1) - gms(3));
fprintf('1 and 4:        %f \t%f\n',q*sqrt((MSE / 2)*((1/n1)+(1/n4))), gms(1) - gms(4));
fprintf('2 and 3:        %f \t%f\n',q*sqrt((MSE / 2)*((1/n2)+(1/n3))), gms(2) - gms(3));
fprintf('2 and 4:        %f \t%f\n',q*sqrt((MSE / 2)*((1/n2)+(1/n4))), gms(2) - gms(4));
fprintf('3 and 4:        %f \t %f\n',q*sqrt((MSE / 2)*((1/n3)+(1/n4))), gms(3) - gms(4));


% disp(q*sqrt((MSE / 2)*((1/n1)+(1/n2))));
% disp(q*sqrt((MSE / 2)*((1/n1)+(1/n3))));
% disp(q*sqrt((MSE / 2)*((1/n1)+(1/n4))));
% 
% 
% disp(q*sqrt((MSE / 2)*((1/n2)+(1/n3))));
% disp(q*sqrt((MSE / 2)*((1/n2)+(1/n4))));
% 
% 
% disp(q*sqrt((MSE / 2)*((1/n3)+(1/n4))));