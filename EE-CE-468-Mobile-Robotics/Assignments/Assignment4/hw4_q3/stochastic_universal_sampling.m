function particles = stochastic_universal_sampling(X, w, N)
% The w array needs to be normalized
    index = [];
    cdf = zeros(1,N);
    % create CDF
    cdf(1) = w(1);
    for i = 2:size(w,2)
        cdf( i) = cdf( i-1) + w(i);
    end

    u = unifrnd(0,1/N);
    for j = 1:N
        i = 1;
        while u > cdf(:, i)
            i = i + 1;
        end
        index = [index i];
        u = u + 1/N;
    end
    X_new = X(:,index);
    
    particles = [X_new;
                ones(1, N)];
    % disp("This is it")
    % particles
end