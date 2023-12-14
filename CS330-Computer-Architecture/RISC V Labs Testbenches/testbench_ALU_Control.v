`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/13/2023 10:58:37 AM
// Design Name: 
// Module Name: testbench_ALU_Control
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

module testbench_ALU_Control();

reg [1:0] ALUOp; reg [3:0] Funct;
wire [3:0] Operation;

ALU_Control ac1(ALUOp, Funct, Operation);

initial begin
ALUOp = 2'b00;
#50 ALUOp = 2'b01;
#50 ALUOp = 2'b10; Funct = 4'b0000;
#100 Funct = 4'b1000;
#100 Funct = 4'b0111;
#100 Funct = 4'b0110;
end
endmodule
