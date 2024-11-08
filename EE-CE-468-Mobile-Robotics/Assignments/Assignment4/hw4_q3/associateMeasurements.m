function [v, H_seq, R_seq, flag] = associateMeasurements(x, P, Z, R, M, g)
% [v, H, R] = associateMeasurements(x, P, Z, R, M, g) returns a set of
% innovation vectors and associated jacobians and measurement covariances
% by matching line features by Mahalanobis distance.
% v: Matrix of innovations for the selected measurements.
% H: Corresponding Jacobians.
% R: Covariance matrices of selected measurements.


% Make use of the measurementFunction.m to find the predicted measurements.

disp("No of Obtained Readings")
size(Z, 2)
first_entry = true;
v = 0;
H_seq = 0;
R_seq = 0;
for i = 1:size(Z,2)
    min_d = inf;
    min_m = 0;
    min_v = 0;
    min_Hx = 0;
    found = false;
    for j = 1:size(M,2)
        [h, H_x] = measurementFunction(x, M(:,j));
        % h;
        % H_x;
        zjt_hat = h;
        v_ijt = Z(:,i) - h;
        % v_ijt;
        % Z(:,i)
        Sigma_ijINt = H_x*P*transpose(H_x) + R(:,:,i);
        % Sigma_ijINt;
        d_curr = transpose(v_ijt)*Sigma_ijINt^(-1)*v_ijt;
        if d_curr <= min_d
            found = true;
            min_d = d_curr;
            min_m = i;
            min_v = v_ijt;
            min_Hx = H_x;
        end
    end
    if found == true
        if first_entry == true && min_d <= g^2
            disp("A Correspondence is Found")
            first_entry = false;
            v = min_v;
            H_seq = min_Hx;
            R_seq = R(:,:,min_m);
        elseif min_d <= g^2
            disp("A Correspondence is Found")
            v(end+1:end+2,:) = min_v;
            H_seq(end+1:end+2,:) = min_Hx;
            R_seq(end+1:end+2,end+1:end+2) = R(:,:,min_m);
        end
    end
end

if first_entry == true
    flag = true;
else
    flag = false;
end
