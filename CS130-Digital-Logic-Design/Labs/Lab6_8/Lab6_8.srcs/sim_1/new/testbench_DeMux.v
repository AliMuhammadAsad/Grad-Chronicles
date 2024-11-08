`timescale 1ns / 1ps

module testbench_DeMux();
reg[1:0] S;
reg En;
wire EnA;
wire EnB;
wire EnC;
wire EnD;

DeMux test(S, En, EnA, EnB, EnC, EnD);

initial begin
#100 S = 2'b00; En = 1'b0;
#100 S = 2'b01; En = 1'b0;
#100 S = 2'b10; En = 1'b0;
#100 S = 2'b11; En = 1'b0;
#100 S = 2'b00; En = 1'b1;

end
endmodule