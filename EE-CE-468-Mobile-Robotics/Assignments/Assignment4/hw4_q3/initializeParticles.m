function [particles]= initializeParticles(N, M)
    i = 0;
    left_max = 0;
    right_max = 0;
    up_max = 0;
    down_max = 0;
    for angle = M(1,:)
        i = i + 1;
        if angle == 0
            if M(2,i) > right_max
                right_max = M(2,i);
            end
        end
        if angle == pi
            if M(2,i) > left_max
                left_max = M(2,i);
            end
        end     
        if angle == pi/2
            if M(2,i) > up_max
                up_max = M(2,i);
            end
        end
        if angle == -pi/2
            if M(2,i) > down_max
                down_max = M(2,i);
            end
        end     
    end
    
    particles = zeros(4,N);

    particles(1,:) = unifrnd(-left_max, right_max,1, N );
    particles(2,:) = unifrnd(-down_max, up_max,1, N );
    particles(3,:) = unifrnd(0, 2*pi,1, N );
    particles(4,:) = ones(1, N);
end