function [new_particles, SIGMA_posterior] = mclStep(particles, SIGMA_seq, Z, Q, R,u,b,M,g)
% SIGMA_seq = It contains all the error covariances corresponding to 

    N = size(particles,2);
    X_new = particles(1:3, :);
    W_new = particles(end, :);
    for i = 1:N
        
        X_prev = particles(1:3,i);
        [X_bar,Fx, Fu]= odometry(X_prev, u, b);
        X_new(1:3,i)=X_bar;
        [z_, H_seq, R_seq, Associated_landmark] = mclAssociation(X_new, SIGMA_seq(:,i:i+2), Z, R, M, g);
        if sum(Associated_landmark) > 0
            % If a correspondence was found
            for j = 1:size(z_,2)
                % The loop is only for when their are multiple measurements
                pdf = measurementModel(z_(:,j), R_seq(:,:,j), M(:,j), X_bar);
                W_new(i) = pdf*W_new;
            end
        % Update the SIGMA_seq
        SIGMA_seq(:,i:i+2) = update_sigma(SIGMA_seq(:,i:i+2), H_seq, Fu, Fx, Q, R);
        end
     
    end
    % Normalize
    W_new = W_new/sum(W_new);
    new_particles = stochastic_universal_sampling(X_new, W_new, N);
    SIGMA_posterior = SIGMA_seq;

   
    
    
    
end