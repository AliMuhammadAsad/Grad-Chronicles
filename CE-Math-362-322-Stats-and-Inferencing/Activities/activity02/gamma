alpha = 2; beta = 0.5;
xmax = 20; x = 0:0.01:xmax;
fx = beta^alpha*x.^(alpha-1).*exp(-beta*x)/gamma(alpha);
k = alpha; theta = 1/beta;
DATA = gamrnd(k, theta, 1, 5000);
BINS = 30;
[COUNTS,EDGES] = histcounts(DATA,BINS);
Ediff = diff(EDGES);
WIDTH = Ediff(1);
AREA = sum(COUNTS)*WIDTH;
figure; bar(EDGES(1:end-1),COUNTS/AREA);
hold on; plot(x, fx, 'k-', 'linewidth', 2)