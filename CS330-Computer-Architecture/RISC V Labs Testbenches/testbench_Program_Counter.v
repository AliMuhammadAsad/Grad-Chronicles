`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/06/2023 12:20:44 AM
// Design Name: 
// Module Name: testbench_Program_Counter
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

module testbench_Program_Counter();

reg clk = 1'b0; reg reset = 1'b0; reg [63:0] PC_In; wire [63:0] PC_Out;

Program_Counter pc(clk, reset, PC_In, PC_Out);

initial begin
PC_In = 64'd0;
#100 PC_In = 64'd10;
#100 PC_In = 64'd420;
#100 reset = 1;
#100 PC_In = 64'd73;
#100 reset = 0;
end

always begin
#5 clk = ~clk;
end
endmodule
