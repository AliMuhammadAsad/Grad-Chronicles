`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2023 10:39:09 AM
// Design Name: 
// Module Name: testbench_RISCV
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


module testbench_RISCV();

reg clk, reset;
wire [63:0] PC_Out, ReadData1, ReadData2, WriteData, Result, Read_Data, imm_data;
wire [31:0] Instruction;
wire [6:0] opcode;
wire [4:0] rs1, rs2, rd;
wire [1:0] ALUOp;
wire Branch, MemRead, MemWrite, MemtoReg, ALUSrc, RegWrite;

RISC_V riscv(clk, reset, PC_Out, ReadData1, ReadData2, WriteData, Result, Read_Data, 
            imm_data, Instruction, 
            opcode, rs1, rs2, rd, 
            ALUOp, Branch, MemRead, MemWrite, MemtoReg, ALUSrc, RegWrite);

initial begin
clk = 1'b0; reset = 1'b0;
//#10 reset = 1'b1;
#20 reset = 1'b0;
#160 reset = 1'b1;
#20 reset = 1'b0;
end
always
    #20 clk = ~clk;
endmodule
