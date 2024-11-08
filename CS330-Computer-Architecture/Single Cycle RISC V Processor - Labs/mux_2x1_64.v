`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/06/2023 11:08:08 AM
// Design Name: 
// Module Name: mux_2x1_64
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

module mux_2x1_64(
    input [63:0] A,
    input [63:0] B,
    input  S,
    output [63:0] Y
    );
    assign Y = (S == 1'b0) ? A : B;
endmodule
