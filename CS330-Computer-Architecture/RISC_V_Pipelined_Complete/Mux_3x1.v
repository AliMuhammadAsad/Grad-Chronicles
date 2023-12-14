`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 10:55:43 AM
// Design Name: 
// Module Name: Mux_3x1
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

module Mux_3x1(
    input [63:0] A,
    input [63:0] B,
    input [63:0] C,
    input [1:0] S,
    output [63:0] Out
    );
    assign Out = (S == 2'b00) ? A : (S == 2'b01) ? B : C;
endmodule