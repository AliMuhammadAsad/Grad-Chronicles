`timescale 1ns / 1ps

module testbench_adder_subtractor();

reg[2:0] A;
reg[2:0] B;
reg sbit;
wire [6:0] S;
wire dp;
adder_subtractor test(A, B, sbit, S, dp);

initial begin
#100 A = 3'b011; B = 3'b100; sbit = 0; //3 + 4
#100 A = 3'b011; B = 3'b100; sbit = 1; //3 - 4
#100 A = 3'b111; B = 3'b111; sbit = 0; //7 + 7
#100 A = 3'b010; B = 3'b110; sbit = 1; //2 - 6

end
endmodule