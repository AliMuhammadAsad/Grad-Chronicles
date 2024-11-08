% Assuming data is a matrix where each column represents a group
data = [14 10 11 16 14;
13 9 12 17 12;
10 12 13 14 13;
11 9 12 16 13;
5 10 13 17 12;
12 11 12 15 14;
10 14 15 17 12];
% Reshape the data into a vector and create group labels
data_vector = data(:);
group_labels = repmat((1:size(data,2)), size(data,1), 1);
group_labels = group_labels(:);
% Perform ANOVA
[p, tbl, stats] = anova1(data_vector, group_labels, 'off');
% Tukey's HSD Test
c = multcompare(stats, 'CType', 'tukey-kramer', 'Alpha', 0.01);
% Display results
disp(c);