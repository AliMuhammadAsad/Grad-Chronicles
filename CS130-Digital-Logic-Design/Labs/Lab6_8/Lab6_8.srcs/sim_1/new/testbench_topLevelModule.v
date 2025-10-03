`timescale 1ns / 1ps

module testbench_topLevelModule();
reg[1:0] S;
reg[3:0] A; reg[3:0] B; reg[3:0] C; reg[3:0] D; wire[6:0] Y;
reg En; wire EnA, EnB, EnC, EnD;

topLevelModule test(S, A, B, C, D, Y, En, EnA, EnB, EnC, EnD);

initial begin
#100 S = 2'b00; A  = 4'b0111; B = 4'b0001; C = 4'b1001; D = 4'b0000; En = 1'b0;
#100 S = 2'b01; A  = 4'b0111; B = 4'b0001; C = 4'b1001; D = 4'b0000; En = 1'b0;
#100 S = 2'b10; A  = 4'b0111; B = 4'b0001; C = 4'b1001; D = 4'b0000; En = 1'b0;
#100 S = 2'b11; A  = 4'b0111; B = 4'b0001; C = 4'b1001; D = 4'b0000; En = 1'b0;
#100 S = 2'b00; A  = 4'b0111; B = 4'b0001; C = 4'b1001; D = 4'b0000; En = 1'b1;

end
endmodule