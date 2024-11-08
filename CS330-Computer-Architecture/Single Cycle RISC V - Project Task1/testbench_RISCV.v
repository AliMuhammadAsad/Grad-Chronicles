`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/03/2023 11:17:46 PM
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
wire [63:0] PC_In, PC_Out, ReadData1, ReadData2, WriteData, Result, Read_Data, imm_data; 
wire [31:0] Instruction; 
wire [6:0] opcode; 
wire [4:0] rs1, rs2, rd; 
wire [1:0] ALUOp; 
wire [63:0] adder_out1, adder_out2; 
wire Branch, MemRead, MemWrite, MemtoReg, ALUSrc, RegWrite, addermuxselect;
wire [63:0] index0, index1, index2, index3, index4;

RISCV_Processor riscv(clk, reset,
    PC_In, PC_Out, ReadData1, ReadData2, WriteData, Result, Read_Data, imm_data,
    Instruction,
    opcode,
    rs1, rs2, rd,
    ALUOp,
    adder_out1, adder_out2,
    Branch, MemRead, MemWrite, MemtoReg, ALUSrc, RegWrite, addermuxselect,
    index0, index1, index2, index3, index4);

initial begin
clk = 0; reset = 1'b1;
#5 reset = 0;
end

always
    #5 clk = ~clk;

endmodule

