sigma = 0.1; %Scale Parameter
DATA = sigma * randn(1, 5000); %Change value from 5000 to 500 for 500 data points
BINS = 30; 
[COUNTS,EDGES] = histcounts(DATA,BINS); 
Ediff=diff(EDGES); 
WIDTH=Ediff(1); 
AREA=sum(COUNTS)*WIDTH;
figure; bar(EDGES(1:end-1), COUNTS/AREA); 
title('Rayleigh Distribution (5000 Data Points)'); grid on;