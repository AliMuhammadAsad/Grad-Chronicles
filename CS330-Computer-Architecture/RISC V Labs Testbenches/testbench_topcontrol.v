`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/13/2023 11:12:57 AM
// Design Name: 
// Module Name: testbench_topcontrol
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

module testbench_topcontrol();

reg [6:0] Opcode; reg[3:0] Funct;
wire [3:0] Operation; 
wire Branch, MemRead, MemtoReg, MemWrite, ALUSrc, RegWrite;

top_control tc1(Opcode, Funct, Branch, MemRead, MemtoReg, MemWrite, ALUSrc, RegWrite, Operation);

initial begin
Opcode = 7'b0110011; Funct = 4'b0000;
#50 Funct = 4'b1000; #50 Funct = 4'b0111; #50 Funct = 4'b0110;
#50 Opcode = 7'b0000011; Funct = 4'bxxxx;
#50 Opcode = 7'b0100011;
#50 Opcode = 7'b1100011;
end
endmodule
