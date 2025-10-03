`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/06/2023 11:02:50 AM
// Design Name: 
// Module Name: testbench_Instruction_Fetch
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

module testbench_Instruction_Fetch();

reg clk = 1'b0; reg reset = 1'b0; wire [31:0] Instruction;

Instruction_Fetch if1(clk, reset, Instruction);

initial begin
#100 reset = 1'b1;
#100 reset = 1'b0;
#100 reset = 1'b1;
#100 reset = 1'b0;
end

always begin
#5 clk = ~clk; 
end

endmodule
