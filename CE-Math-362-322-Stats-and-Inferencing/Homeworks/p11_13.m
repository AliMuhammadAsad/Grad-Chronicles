data = [7 8 5;
7 9 6;
8 8 5;
7 10 7;
9 9 4;
NaN 10 8;
NaN 8 NaN;
];

a = 0.05;
ns = sum(~isnan(data));
grp_means = mean(data, 1, 'omitnan');
xbar = mean(data(:), 'omitnan');
SSC = sum(ns.*(grp_means - xbar).^2);
SST = sum((data(:) - xbar).^2, 'omitnan');
SSE = SST - SSC;
C = length(ns);
N = 18; %elements in the data
dfc = C - 1; dfe = N - C; dft = N - 1;
MSC = SSC / dfc; MSE = SSE / dfe; 
F = MSC / MSE;
F_val = finv(1 - a, dfc, dfe);
[p, tb1, stats] = anova1(data);
