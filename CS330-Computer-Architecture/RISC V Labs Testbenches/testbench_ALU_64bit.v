`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/15/2023 11:09:08 PM
// Design Name: 
// Module Name: testbench_ALU_64bit
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module testbench_ALU_64bit();

reg [63:0] a, b; reg [3:0] ALUop; reg CarryIn;
wire [63:0] Result; wire CarryOut, Zero;

ALU64bit alu64_0(a, b, CarryIn, ALUop, Result, CarryOut, Zero);

initial begin
a = 64'd276; b = 64'd133; CarryIn = 0; ALUop = 4'b0000;

#10 ALUop = 4'b0001; 
#10 ALUop = 4'b0010;
#10 ALUop = 4'b0110; 
#10 ALUop = 4'b1100;

#10 ALUop = 4'b0000; CarryIn = 1;
#10 ALUop = 4'b0001; CarryIn = 1;
#10 ALUop = 4'b0010; CarryIn = 1;
#10 ALUop = 4'b0110; CarryIn = 1;
#10 ALUop = 4'b1100; CarryIn = 1;

#10 ALUop = 4'b0000; a = 64'd0; b = 64'd0; CarryIn = 0;
#10 ALUop = 4'b0000; a = 64'd0; b = 64'd0; CarryIn = 1;
#10 ALUop = 4'b0000; a = 64'd1; b = 64'd4; CarryIn = 0;
#10 ALUop = 4'b0000; a = 64'd1; b = 64'd4; CarryIn = 1;
end

endmodule
