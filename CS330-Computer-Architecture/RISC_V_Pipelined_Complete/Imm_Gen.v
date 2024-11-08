`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 10:55:43 AM
// Design Name: 
// Module Name: Imm_Gen
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

module Imm_Gen(
    input [31:0] Instruction,
    output [63:0] Imm
    );
wire [11:0] load, store, cond; //12-bit data to be extended
reg [11:0] q; wire [51:0] ext;
assign ext = {52{Instruction[31]}};
assign load = Instruction[31:20];
assign store = {Instruction[31:25], Instruction[11:7]};
assign cond = {Instruction[31], Instruction[7], Instruction[30:25], Instruction[11:8]};
always @(Instruction or q) begin
    case(Instruction[6:5])
        00 : q = load;
        01 : q = store;
        10 : q = cond;
        11 : q = cond;
    endcase
end
assign Imm = {ext, q};
endmodule
