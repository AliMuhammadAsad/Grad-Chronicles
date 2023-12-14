`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/13/2023 10:49:09 AM
// Design Name: 
// Module Name: testbench_Control_Unit
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

module testbench_Control_Unit();

reg [6:0] Opcode; wire [1:0] ALUOp;
wire Branch, MemRead, MemtoReg, MemWrite, ALUSrc, RegWrite; 

Control_Unit cu1(Opcode, Branch, MemRead, MemtoReg, ALUOp, MemWrite, ALUSrc, RegWrite);

initial begin
Opcode = 7'b0000000;
#100 Opcode = 7'b0110011; //R-Type
#100 Opcode = 7'b0000011; //I-Type(ld)
#100 Opcode = 7'b0100011; //S-Type(sd)
#100 Opcode = 7'b1100011; //Sb-Type(beq)
end
endmodule
