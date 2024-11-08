`timescale 1ns / 1ps

module testbench_ALU_1_bit();

reg a, b, CarryIn; reg [3:0] ALUop;
wire CarryOut, Result;

ALU_1_bit alu1(a, b, CarryIn, ALUop, Result, CarryOut);

initial begin
a = 1; b = 1; CarryIn = 0; ALUop = 4'b0000;
#100 ALUop = 4'b0001; a = 1; b = 1;
#100 ALUop = 4'b0010; a = 1; b = 1; CarryIn = 1;
#100 ALUop = 4'b0110; a = 0; b = 0;
#100 ALUop = 4'b1100; a = 0; b = 0;
end
endmodule