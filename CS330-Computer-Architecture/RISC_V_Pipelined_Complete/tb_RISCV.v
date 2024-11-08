`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 12:07:49 PM
// Design Name: 
// Module Name: tb_RISCV
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

module tb_RISCV();

reg clk, reset;
wire [4:0] RD, RS1, RS2, IDEX_RD, IDEX_RS1, IDEX_RS2, EM_RD, MW_RD;
wire IDEX_MemRead, EM_MemRead;
wire [6:0] Opcode;
wire Branch, EM_Branch, MemRead, MemWrite, MemtoReg, RegWrite, ALUSrc, stall;
wire [1:0] ALUOp;
wire [31:0] Instruction, IFID_Instruction;
wire [63:0] PC_In, PC_Out, IFID_PC_Out, ReadData1, ReadData2, IDEX_ReadData1, IDEX_ReadData2, Imm, IDEX_Imm, 
Adder2Out, EM_Adder2Out, Result, EM_Result, EM_WriteData,
Read_Data, MW_Read_Data, WriteData;
wire [63:0] index0, index1, index2, index3, index4;

RISC_V_Processor risc(clk, reset,
RD, RS1, RS2, IDEX_RD, IDEX_RS1, IDEX_RS2, EM_RD, MW_RD,
IDEX_MemRead, EM_MemRead,
Opcode,
stall,
Branch, EM_Branch, MemRead, MemWrite, MemtoReg, RegWrite, ALUSrc,
ALUOp,
Instruction, IFID_Instruction,
PC_In,
PC_Out, IFID_PC_Out, ReadData1, ReadData2, IDEX_ReadData1, IDEX_ReadData2, Imm, IDEX_Imm, Adder2Out, EM_Adder2Out,
Result, EM_Result, EM_WriteData, Read_Data, MW_Read_Data, WriteData,
index0, index1, index2, index3, index4
);

initial begin
clk = 0; reset = 1;
#5 reset = 0;
#5 reset = 0;

end
always
    #5 clk = ~ clk;
endmodule
