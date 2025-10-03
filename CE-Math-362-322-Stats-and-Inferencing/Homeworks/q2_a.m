data = [14 10 11 16 14;
13 9 12 17 12;
10 12 13 14 13;
11 9 12 16 13;
5 10 13 17 12;
12 11 12 15 14;
10 14 15 17 12;];
a = 0.01;
ns = sum(~isnan(data)); grp_means = mean(data, 1, 'omitnan'); xbar = mean(data(:), 'omitnan');
SSC = sum(ns.*(grp_means - xbar).^2); SST = sum((data(:) - xbar).^2, 'omitnan'); SSE = SST - SSC;
c = length(ns); N = 35; dfc = c - 1; dfe = N -c; dft = N - 1;
MSC = SSC / dfc; MSE = SSE / dfe; F = MSC / MSE;
[p, tbs, stats] = anova1(data);
Warning: MATLAB has disabled some advanced graphics rendering features by switching to software OpenGL. For more information, click here. 
f_val = finv(1-a, dfc, dfe);
