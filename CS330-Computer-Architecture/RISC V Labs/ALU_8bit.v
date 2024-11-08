`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/13/2023 12:02:28 PM
// Design Name: 
// Module Name: ALU_8bit
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


module ALU_8bit(
    input [7:0] a,
    input [7:0] b,
    input CarryIn,
    input [3:0] ALUop,
    output [7:0] Result,
    output CarryOut
    );

wire c0, c1, c2, c3, c4, c5, c6;
ALU_1_bit alu0(a[0], b[0], CarryIn, ALUop, Result[0], c0);
ALU_1_bit alu1(a[1], b[1], c0, ALUop, Result[1], c1);
ALU_1_bit alu2(a[2], b[2], c1, ALUop, Result[2], c2);
ALU_1_bit alu3(a[3], b[3], c2, ALUop, Result[3], c3);
ALU_1_bit alu4(a[4], b[4], c3, ALUop, Result[4], c4);
ALU_1_bit alu5(a[5], b[5], c4, ALUop, Result[5], c5);
ALU_1_bit alu6(a[6], b[6], c5, ALUop, Result[6], c6);
ALU_1_bit alu7(a[7], b[7], c6, ALUop, Result[7], CarryOut); 

endmodule
