function pdf = measurementModel(z, R, M, X)
  % The function returns the weight of the i_th particle
    mu_z = [angdiff(M(1,1) - X(3,1));
         M(2,1) - ( X(1,1)*cos(M(1,1)) + X(2,1)*sin(M(1,1)));
    ]; %This is the expected value of z given x_bar
    pdf = mvnpdf(z,mu_z,R);
end
