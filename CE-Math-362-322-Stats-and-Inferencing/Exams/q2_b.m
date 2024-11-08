data = [
14 10 11 16 14;
13 9 12 17 12;
10 12 13 14 13;
11 9 12 16 13;
5 10 13 17 12;
12 11 12 15 14;
10 14 15 17 12
];



% Flatten the data into a vector
data_vector = data(:);

% Calculate the upper and lower bounds for outliers
Q3 = quantile(data_vector, 0.75);
Q1 = quantile(data_vector, 0.25);
IQR = Q3 - Q1;
upper_outlier_bound = Q3 + 1.5 * IQR;
lower_outlier_bound = Q1 - 1.5 * IQR;

% Find upper and lower outliers
upper_outliers = data_vector(data_vector > upper_outlier_bound);
lower_outliers = data_vector(data_vector < lower_outlier_bound);

% Calculate upper adjustment
upper_adjustment = max(upper_outliers);

% Calculate 75th percentile, median, and 25th percentile
percentiles = prctile(data_vector, [75, 50, 25]);
Q3_calculated = percentiles(1);
median_calculated = percentiles(2);
Q1_calculated = percentiles(3);

% Calculate lower adjustment
lower_adjustment = min(lower_outliers);

% Display the results
disp(['Upper Outlier Bound: ' num2str(upper_outlier_bound)]);
disp(['Lower Outlier Bound: ' num2str(lower_outlier_bound)]);
disp(['Upper Outliers: ' num2str(upper_outliers')]);
disp(['Lower Outliers: ' num2str(lower_outliers')]);
disp(['Upper Adjustment: ' num2str(upper_adjustment)]);
disp(['75th Percentile (Q3): ' num2str(Q3_calculated)]);
disp(['Median: ' num2str(median_calculated)]);
disp(['25th Percentile (Q1): ' num2str(Q1_calculated)]);
disp(['Lower Adjustment: ' num2str(lower_adjustment)]);