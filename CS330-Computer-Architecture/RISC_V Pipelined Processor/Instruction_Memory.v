`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2023 09:12:45 AM
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
    
reg [7:0] registers [15:0]; //Initialising 32 registers of 8-bits

initial begin
registers[0] = 8'b10000011;
registers[1] = 8'b00110100;
registers[2] = 8'b10000101;
registers[3] = 8'b00000010;

registers[4] = 8'b10110011;
registers[5] = 8'b10000100;
registers[6] = 8'b10011010;
registers[7] = 8'b00000000;

registers[8] = 8'b10010011;
registers[9] = 8'b10000100;
registers[10] = 8'b00010100;
registers[11] = 8'b00000000;

registers[12] = 8'b00100011;
registers[13] = 8'b00110100;
registers[14] = 8'b10010101;
registers[15] = 8'b00000010;
end
always @(Inst_Address)
    Instruction = {registers[Inst_Address + 3], registers[Inst_Address + 2], registers[Inst_Address + 1], registers[Inst_Address]};

endmodule
