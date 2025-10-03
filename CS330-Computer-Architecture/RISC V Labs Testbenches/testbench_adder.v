`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/05/2023 11:12:19 PM
// Design Name: 
// Module Name: testbench_adder
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

module testbench_adder();

reg [63:0] a, b; wire [63:0] out;

Adder a1(a, b, out);

initial begin;
a = 64'd10; b = 64'd4; 

#50 a = 64'd14; b = 64'd1;
#50 a = 64'd15; b = 64'd5;
#50 a = 64'd20; b = 64'd100;
end
endmodule
