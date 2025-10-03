`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/13/2023 10:59:07 AM
// Design Name: 
// Module Name: ALU_1_bit
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

module ALU_1_bit(
    input a,
    input b,
    input CarryIn,
    input [3:0] ALUop,
    output reg Result,
    output reg CarryOut
    );
always @(*) begin
//And
if(ALUop == 4'b0000) begin Result = a & b; CarryOut = 0; end
//OR
else if(ALUop == 4'b0001) begin Result = a | b; CarryOut = 0; end
//Add
else if(ALUop == 4'b0010) begin Result = a + b + CarryIn; 
CarryOut = (a & CarryIn) | (b & CarryIn) | (a & b); end
//Sub
else if(ALUop == 4'b0110) begin Result = a - b - CarryIn;
CarryOut = (a & CarryIn) | (b & CarryIn) | (a & b); end
else if(ALUop == 4'b1100) begin Result = ~(a | b); CarryOut = 0; end
end   

endmodule

//assign CarryOut = (a & CarryIn) | (b & CarryIn) | (a & b); 
//assign Result = (ALUop == 4'b0000) ? (a & b) : 
//                (ALUop == 4'b0001) ? (a | b) :
//                (ALUop == 4'b0010) ? (a + b) : 
//                (ALUop == 4'b0110) ? (a - b) :
//                (ALUop == 4'b1100) ? ~(a | b) : 0;