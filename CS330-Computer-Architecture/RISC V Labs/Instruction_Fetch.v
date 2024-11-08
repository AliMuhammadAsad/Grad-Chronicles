`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/06/2023 10:39:47 AM
// Design Name: 
// Module Name: Instruction_Fetch
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

module Instruction_Fetch(
    input clk,
    input reset,
    output [31:0] Instruction
    );
    
wire [63:0] PC_In, PC_Out;

Program_Counter pc(.clk(clk), .reset(reset), .PC_In(PC_In), .PC_Out(PC_Out));
Instruction_Memory im(.Inst_Address(PC_Out), .Instruction(Instruction));
Adder add(.a(PC_Out), .b(64'd4), .out(PC_In));
    
endmodule
