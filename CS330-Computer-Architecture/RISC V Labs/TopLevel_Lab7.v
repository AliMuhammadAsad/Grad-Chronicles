`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2023 11:10:54 PM
// Design Name: 
// Module Name: TopLevel_Lab7
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


module TopLevel_Lab7(
    input [31:0] instruction,
    input clk,
    input reset,
    input RegWrite,
    input [63:0] WriteData,
    output wire [63:0] ReadData1,
    output wire [63:0] ReadData2
    );
wire [6:0] opcode, funct7; wire [4:0] rd, rs1, rs2; wire [2:0] funct3;

inst_parser_32 ip(instruction, opcode, rd, funct3, rs1, rs2, funct7);
regiserFile rf(.clk(clk), .reset(reset), .WriteData(WriteData), .RS1(rs1), .RS2(rs2), .RD(rd), .RegWrite(RegWrite), .ReadData1(ReadData1), .ReadData2(ReadData2));

endmodule
