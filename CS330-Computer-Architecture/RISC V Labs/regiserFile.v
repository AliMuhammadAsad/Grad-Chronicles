`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/21/2023 01:07:01 PM
// Design Name: 
// Module Name: regiserFile
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

module regiserFile(
    input clk,
    input reset,
    input [63:0] WriteData,
    input [4:0] RS1,
    input [4:0] RS2,
    input [4:0] RD,
    input RegWrite,
    output reg [63:0] ReadData1,
    output reg [63:0] ReadData2
    );

reg [63:0] registers [63:0];
integer i;
initial begin
for (i = 0; i < 63; i = i + 1) begin
    registers[i] = 64'd0 + i;
    end end

always @(posedge clk or reset == 1) begin
    ReadData1 = registers[RS1]; ReadData2 = registers[RS2];
    if (RegWrite == 1) registers[RD] = WriteData;
    if (reset == 1) begin
        ReadData1 = 64'd0; ReadData2 = 64'd0;
    end
end  

endmodule



//always @(posedge clk) begin
//if(RegWrite == 1) registers[RD] = WriteData; end
    
//always @(*) begin
//ReadData1 = registers[RS1]; ReadData2 = registers[RS2];
//if(reset == 1) begin
//ReadData1 = 64'd0; ReadData2 = 64'd0;
//end end