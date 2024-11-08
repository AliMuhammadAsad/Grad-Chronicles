function [z_, H_seq, R_seq, Associated_landmarks] = mclAssociation(x, P, Z, R, M, g)

first_entry = true;
H_seq = [];
R_seq = [];
z_ = [];
Associated_landmarks = zeros(size(M,2)) ;%Associated landmark index
for i = 1:size(Z,2)
    min_d = inf;
    min_m = 0;
    min_Hx = 0;
    found = false;
    for j = 1:size(M,2)
        [h, H_x] = measurementFunction(x, M(:,j));
        v_ijt = Z(:,i) - h;
        % h_size = size(H_x)
        % P_size = size(P)
        % R_size = size(R)
        % RR = size(R(:,:,i))
        % bruh = H_x*P*H_x'+R(:,:,i)
        
        % R(:,:,i)
        Sigma_ijINt = H_x*P*H_x'+R(:,:,i);
        d_curr = transpose(v_ijt)*Sigma_ijINt^(-1)*v_ijt;
        if d_curr <= min_d
            found = true;
            min_d = d_curr;
            min_m = i;
            min_Hx = H_x;
            Associated_landmarks(j) = 1;
        end
    end
    if found == true
        if first_entry == true && min_d <= g^2
            % disp("A Correspondence is Found")
            first_entry = false;
            z_ = [z_ Z(:, i)];
            H_seq = min_Hx;
            R_seq = R(:,:,min_m);
        elseif min_d <= g^2
            % disp("A Correspondence is Found")
            z_ = [z_ Z(:, i)];
            H_seq(end+1:end+2,:) = min_Hx;
            R_seq(end+1:end+2,end+1:end+2) = R(:,:,min_m);
        end
    end
end

