lambda = 0.5; %Rate Parameter
DATA = exprnd(1/lambda, 1, 500); %Change the value from 500 to 5000 for 5000 data points
BINS = 30; 
[COUNTS, EDGES] = histcounts(DATA,BINS); 
Ediff=diff(EDGES); 
WIDTH=Ediff(1);
AREA= sum(COUNTS)*WIDTH;
figure; bar(EDGES(1:end-1),COUNTS/AREA);
title('Exponential Distribution (500 Data Points)'); 
grid on;