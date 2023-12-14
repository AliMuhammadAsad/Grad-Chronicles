`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/05/2023 11:37:47 PM
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
    input [63:0] PC_In,
    output reg [63:0] PC_Out
    );

initial 
	PC_Out=64'd0;

	always @ (posedge clk or posedge reset)
	begin
		if (reset)
			PC_Out=64'd0;
		else
			PC_Out=PC_In;
	end


//always @(posedge clk) begin
//    if (reset <= 0) PC_Out <= PC_In;
//    else PC_Out = 64'd0;
//end 
//always @(reset == 1) begin
//    PC_Out <= 64'd0;
//end
endmodule
