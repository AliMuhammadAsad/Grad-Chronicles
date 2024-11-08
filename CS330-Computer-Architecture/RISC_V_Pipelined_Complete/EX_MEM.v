`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 10:55:43 AM
// Design Name: 
// Module Name: EX_MEM
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

module EX_MEM(
    input clk, reset,
    input Branch, MemRead, MemWrite, MemtoReg, RegWrite, 
    input Zero,
    input addermuxselect,
    input [4:0] RD, 
    input [63:0] Adder2Out, Result, WriteData,
    output reg EM_Branch, EM_MemRead, EM_MemWrite, EM_MemtoReg, EM_RegWrite,
    output reg EM_Zero,
    output reg EM_addermuxselect,
    output reg [4:0] EM_RD,
    output reg [63:0] EM_Adder2Out, EM_Result, EM_WriteData
    );
always @(posedge clk or posedge reset) begin
    if (reset == 1'b1) begin
        EM_Branch = 0; EM_MemRead = 0; EM_MemWrite = 0; EM_MemtoReg = 0;
        EM_RegWrite = 0; EM_Zero = 0; EM_RD = 0; EM_Adder2Out = 0;
        EM_Result = 0; EM_WriteData = 0; EM_addermuxselect = 0;
    end
    else begin
        EM_Branch = Branch; EM_MemRead = MemRead; EM_MemWrite = MemWrite; 
        EM_MemtoReg = MemtoReg; EM_RegWrite = RegWrite; EM_Zero = Zero; 
        EM_RD = RD; EM_Adder2Out = Adder2Out; EM_Result = Result; 
        EM_WriteData = WriteData; EM_addermuxselect = addermuxselect;
    end 
end
endmodule

