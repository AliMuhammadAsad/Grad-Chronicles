`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2023 10:59:17 AM
// Design Name: 
// Module Name: testbench_InstructionMemory
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


module testbench_InstructionMemory();
reg [63:0] Inst_Address; wire [31:0] Instruction;

Instruction_Memory im1(Inst_Address, Instruction);

initial begin
Inst_Address = 64'd0;
#100 Inst_Address = 64'd4;
#100 Inst_Address = 64'd8;
#100 Inst_Address = 64'd12;
end
endmodule
