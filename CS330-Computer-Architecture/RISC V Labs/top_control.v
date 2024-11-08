`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/13/2023 11:09:04 AM
// Design Name: 
// Module Name: top_control
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

module top_control(
    input [6:0] Opcode,
    input [3:0] Funct,
    output Branch,
    output MemRead,
    output MemtoReg,
    output MemWrite,
    output ALUSrc,
    output RegWrite,
    output [4:0] Operation
    );
wire [1:0] ALUOp;

Control_Unit cu1(Opcode, Branch, MemRead, MemtoReg, ALUOp, MemWrite, ALUSrc, RegWrite);
ALU_Control ac1(ALUOp, Funct, Operation);

endmodule
