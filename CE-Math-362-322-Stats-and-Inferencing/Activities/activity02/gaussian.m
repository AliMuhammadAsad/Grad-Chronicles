mu = 2.5; sigma = 1.2; %Mean and Standard Deviation
DATA = mu + sigma * randn(1, 500); %Change value of randn from 500 to 5000 for data points
BINS = 30; 
[COUNTS,EDGES] = histcounts(DATA,BINS); 
Ediff=diff(EDGES);
WIDTH=Ediff(1); AREA = sum(COUNTS)*WIDTH;
figure; bar(EDGES(1:end-1),COUNTS/AREA);
title('Gaussian(Normal) Distribution (500 Data Points)');
grid on;