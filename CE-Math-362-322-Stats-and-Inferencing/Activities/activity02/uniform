a = 2; b = 20; %Minimum and Maximum Values
DATA = unifrnd(a, b, 1, 500);
BINS = 30;
[COUNTS,EDGES] = histcounts(DATA,BINS);
Ediff = diff(EDGES);
WIDTH = Ediff(1);
AREA = sum(COUNTS)*WIDTH;
figure; bar(EDGES(1:end-1),COUNTS/AREA);
title('UNIFORM DISTRIBUTION (500 Data Points)'); grid on;
hold on; plot(linspace(a, b, 1000), 1/(b-1)*ones(size(linspace(a, b, 10000))), 'k-', 'linewidth', 2)