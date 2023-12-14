`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 11:16:44 AM
// Design Name: 
// Module Name: Hazard_Detection_Unit
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

module Hazard_Detection_Unit(
    input [4:0] RS1, RS2, IDEX_RD,
    input IDEX_MemRead,
    output reg stall // IFID_Write, PC_Write, IDEX_MuxOut,
    );

always @(*) begin
    if (IDEX_MemRead && (IDEX_RD == RS1 || IDEX_RD == RS2)) begin
        stall = 1; // IDEX_MuxOut = 1; IFID_Write = 0; PC_Write = 0; 
    end
    else begin
        stall = 0; // IDEX_MuxOut = 0; IFID_Write = 1; PC_Write = 1; 
    end
end
endmodule
