%% 2d
% Number of samples
num_samples = 1000;

% Draw samples from Gaussian distribution
initial_samples = mvnrnd([0; 0; 0], [0.01, 0, 0; 0, 0.01, 0; 0, 0, 10000], num_samples);

% Plot 3D samples
figure;
% scatter3(initial_samples(:, 1), initial_samples(:, 2), initial_samples(:, 3), 'b.');
scatter(initial_samples(:, 1), initial_samples(:, 2), 'b.');
xlabel('X');
ylabel('Y');
zlabel('Theta');
title('Samples from Gaussian Distribution');

% Propagate samples according to motion equation
propagated_samples = zeros(num_samples, 3);
for i = 1:num_samples
    % Motion model (assuming distance covered in one time step is 1)
    propagated_samples(i, :) = initial_samples(i, :) + [cos(initial_samples(i, 3)), sin(initial_samples(i, 3)), 0];
end

% Hold on to keep the current plot and add new plots
hold on;

% Plot 2D samples at time 1
scatter(propagated_samples(:, 1), propagated_samples(:, 2), 'r.');
xlabel('X');
ylabel('Y');
title('Samples of x-y state at time 1');
legend('initial samples', 'predicted samples');
% Release the hold
hold off;


% the radius in each direction is the standard deviation σ_x and σ_y parametrized by a scale factor s, 
% known as the Mahalanobis radius of the ellipsoid

% We can solve this equation using a χ^2 table or using Matlab function s=chi2inv(p, 2) or simply:
% s= -2log(1-p)

% Constants
dt = 1;  % time step
Q = diag([0, 0, 0]);  % process noise covariance
R = diag([0.1, 0.1]);  % measurement noise covariance (assumed values)

% Initial state estimate
x_hat = [0; 0; 0];
% Initial state covariance
P = [0.01, 0, 0; 0, 0.01, 0; 0, 0, 10000];

% Simulation parameters
num_steps = 1;  % number of steps

% Measurement Noise Covariance
R_measurement = 0.01;

% Kalman Filter Loop
for k = 1:num_steps
    v_x = 1;
    w = 0;       % omega = 0
    % Prediction Step
    x_bar = x_hat + [v_x*dt*cos(x_hat(3,1)); v_x*dt*sin(x_hat(3,1)); w*dt];  % since there is no control input, the state remains the same
    G = [1 0 -v_x*dt*sin(x_hat(3,1)); 0 1 v_x*dt*cos(x_hat(3,1)); 0 0 1];  % state transition matrix (no change in state)

    % Update Covariance
    P_bar = G * P * G' + Q;

    % Store predicted state and covariance
    predicted_states(k, :) = x_bar;
    predicted_covariances(k, :, :) = P_bar;
    
%     hold on
%     for k = 1:num_steps
%         plotErrorEllipse(predicted_states(k, 1:2), squeeze(predicted_covariances(k, 1:2, 1:2)), 0.95);
%     end
    hold off
    
    % Simulate a noisy measurement generate based on a normal distribution with mean 0 and standard deviation
    d = sqrt(x_bar(1)^2 + x_bar(2)^2); 
%     theta = atan2(x_bar(2), x_bar(1));
     R_measurment = 0.0001;
    E = mvnrnd(0, R_measurment);
    z_k = d + E; % Noisy measurment
%     z_k = [d; theta] + E; % Noisy measurment

    x = x_bar(1, :);
    y = x_bar(2, :);
    % Compute partial derivatives
    partial_d_x = x / sqrt(x^2 + y^2);
    partial_d_y = y / sqrt(x^2 + y^2);
    
    partial_theta_x = -y / (x^2 + y^2);
    partial_theta_y = x / (x^2 + y^2);
    
    % Construct Jacobian matrix H
    H = [partial_d_x, partial_d_y, 0];

% H = [1 0];
    h_xk_bar = H * x_bar;

    % Kalman Gain
    S = H * P_bar * H' + R_measurement;
    K = P_bar * H' / S;

    % Update State Estimate
    y = z_k - h_xk_bar;
    x_hat_up = x_bar + K * y;

    % Update Covariance
    P_up = (eye(3) - K * H) * P_bar;

    
    % Store updated state and covariance
    updated_states(k, :) = x_hat_up;
    updated_covariances(k, :, :) = P_up;
end


% Plotting Part (c) - Propagated samples and error ellipse for predicted step
figure;
scatter(propagated_samples(:, 1), propagated_samples(:, 2), 'b.');
hold on;
for k = 1:num_steps
    plotErrorEllipse(predicted_states(k, 1:2), squeeze(predicted_covariances(k, 1:2, 1:2)), 0.95);
end
xlabel('X');
ylabel('Y');
title('Propagated Samples and Predicted Error Ellipse');
legend('propagated samples', 'Error in prediction');
hold off;

% Plotting Part (d) - Propagated samples, error ellipse for predicted step, and error ellipse for updated step
figure;
scatter(propagated_samples(:, 1), propagated_samples(:, 2), 'b.', 'DisplayName', 'Propagated Samples');
hold on;
for k = 1:num_steps
    plotErrorEllipse(predicted_states(k, 1:2), squeeze(predicted_covariances(k, 1:2, 1:2)), 0.95);
end
for k = 1:num_steps
    plotErrorEllipse(updated_states(k, 1:2), squeeze(updated_covariances(k, 1:2, 1:2)), 0.95);
end
xlabel('X');
ylabel('Y');
title('Propagated Samples with Predicted and Updated Error Ellipse');
legend('propagated samples', 'Error in prediction', 'Error in Measurment');
hold off;

