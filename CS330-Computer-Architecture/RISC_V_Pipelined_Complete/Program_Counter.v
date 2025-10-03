`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 10:55:43 AM
// Design Name: 
// Module Name: Program_Counter
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

module Program_Counter(
    input clk,
    input reset,
    input stall,
    input [63:0] PC_In,
    output reg [63:0] PC_Out
    );

initial
	PC_Out=64'd0;
	always @ (posedge clk or posedge reset)
	   if (reset == 1'b1) PC_Out = 64'b0;
	   else if (stall == 1'b1) PC_Out = PC_Out;
	   else PC_Out = PC_In;
//        PC_Out = (reset == 1'b1) ? 64'b0: PC_In;
//	begin
//		if (reset)
//			PC_Out=64'd0;
//		else
//			PC_Out=PC_In;
//	end    
endmodule