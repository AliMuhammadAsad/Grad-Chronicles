clc; clear all; close all;

% Your data
xi = [2216, 2237, 2249, 2204, 2225, 2301, 2281, 2263, 2318, 2255, 2275, 2295];

% Calculate the sample variance
mean_xi = mean(xi); % Calculate the mean
n = length(xi); % Get the number of data points
squared_differences = (xi - mean_xi).^2; % Square the differences from the mean
sample_variance = sum(squared_differences) / (n - 1); % Calculate the sample variance

disp(['Sample Variance: ', num2str(sample_variance)]);

num2str(mean_xi-2.201*(sqrt(sample_variance/12)))
num2str(mean_xi+2.201*(sqrt(sample_variance/12)))
num2str(mean_xi-1.796*(sqrt(sample_variance/12)))
