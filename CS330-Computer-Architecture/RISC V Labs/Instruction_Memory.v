`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2023 10:52:10 AM
// Design Name: 
// Module Name: Instruction_Memory
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


module Instruction_Memory(
    input [63:0] Inst_Address,
    output reg [31:0] Instruction
    );
    
reg [7:0] registers [31:0]; //Initialising 32 registers of 8-bits
integer i;
initial begin //Storing dummy data in the registers
//Each register of 8-bits
for (i = 0; i < 32; i = i + 1) begin
    registers[i] = 8'd0 + i;
end
end

always @(*)
assign Instruction = {registers[Inst_Address + 3], registers[Inst_Address + 2], registers[Inst_Address + 1], registers[Inst_Address]};

endmodule
