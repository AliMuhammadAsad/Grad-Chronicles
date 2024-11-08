`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/13/2023 12:08:05 PM
// Design Name: 
// Module Name: testbench_ALU_8bit
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

module testbench_ALU_8bit();
reg [7:0] a, b; reg CarryIn; reg [3:0] ALUop;
wire [7:0] Result; wire CarryOut;

ALU_8bit alu8_0(a, b, CarryIn, ALUop, Result, CarryOut);

initial begin

a = 8'b00001010; b = 8'b00000011; CarryIn = 0; ALUop = 4'b0000;

#100 ALUop = 4'b0001; 
#100 ALUop = 4'b0010;
#100 ALUop = 4'b0110; 
#100 ALUop = 4'b1100;

#100 ALUop = 4'b0000; CarryIn = 1;
#100 ALUop = 4'b0001; CarryIn = 1;
#100 ALUop = 4'b0010; CarryIn = 1;
#100 ALUop = 4'b0110; CarryIn = 1;
#100 ALUop = 4'b1100; CarryIn = 1;

end
endmodule
