`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2023 11:16:12 PM
// Design Name: 
// Module Name: testbench_toplevel_Lab7
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


module testbench_toplevel_Lab7();

reg [31:0] instruction;
reg [63:0] WriteData; wire [63:0] ReadData1, ReadData2;
reg clk, reset, RegWrite;

TopLevel_Lab7 tl7(instruction, clk, reset, RegWrite, WriteData, ReadData1, ReadData2);

initial begin
clk = 0;
RegWrite = 0; reset = 1; instruction = 32'h01548133; WriteData = 64'b1010101101010111000111;
#10 reset = 0;
#10 RegWrite = 1;
end

always
#5 clk = ~clk;

endmodule
