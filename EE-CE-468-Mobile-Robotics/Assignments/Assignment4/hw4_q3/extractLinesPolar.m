function [z, R, segends] = extractLinesPolar(theta, rho, C_TR, params)
    if isempty(theta)
        z = [];
        R = [];
        segends = [];
        return;
    end
    
    [x,y] = pol2cart(theta, rho);
    [alpha, r, segends, ~, idx] = extractLines([x;y], params);
    
    z = [alpha, r]';
    
    R = zeros(2, 2, size(alpha, 2));
    
    N = size(alpha, 1);
    n_param = size(alpha, 2);
    if size(C_TR, 1) > 0
        R = zeros(2, 2, n_param);
            
        for i = 1:N
            range =idx(i, 1):idx(i, 2);
            nPointsInSegment = size(range, 2);
            [~, ~, R(:, :, i)] = fitLinePolar(theta(range), rho(range), [ C_TR(range, range),  zeros(nPointsInSegment);  zeros(nPointsInSegment),  C_TR(N + range, N + range)]);
        end
    end
end
