function [SIGMA] = update_sigma(SIGMA, H, Fu, Fx, Q, R)
    % size_H = size(H)
    % H
    % size_SIGMA = size(SIGMA)
    SIGMA_BAR = Fx*SIGMA*Fx'+Fu*Q*Fu';
    SigmaINt = H*SIGMA_BAR*H' + R;
    Kk = SIGMA_BAR*H'*(SigmaINt)^(-1);
    SIGMA = SIGMA_BAR - Kk*SigmaINt*Kk'; 
end
