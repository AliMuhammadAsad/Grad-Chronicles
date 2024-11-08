`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/11/2023 01:51:42 PM
// Design Name: 
// Module Name: Pipelined_RISC_V_tb
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

module Pipelined_RISC_V_tb();

reg clk, reset;

RISC_V_Pipelined riscv(clk, reset);

initial begin
clk = 1'b0; reset = 1'b0;
#10 reset = 1'b1;
#10 reset = 1'b0;
end

always
    #10 clk = ~clk;

endmodule


//reg clk, reset;
//wire [4:0] RD, RS1, RS2, IDEX_RD, IDEX_RS1, IDEX_RS2, EM_RD, MW_RD;
//wire [6:0] Opcode;
//wire [31:0] Instruction, IFID_Instruction;
//wire [63:0] PC_Out, IFID_PC_Out, ReadData1, ReadData2, IDEX_ReadData1, IDEX_ReadData2, Imm, IDEX_Imm, 
//Adder2Out, EM_Adder2Out, Result, EM_Result, EM_WriteData,
//Read_Data, MW_Read_Data, WriteData;

//RISC_V_Pipelined risc(clk, reset,
//RD, RS1, RS2, IDEX_RD, IDEX_RS1, IDEX_RS2, EM_RD, MW_RD,
//Opcode, 
//Instruction, IFID_Instruction, 
//PC_Out, IFID_PC_Out, ReadData1, ReadData2, IDEX_ReadData1, IDEX_ReadData2, Imm, IDEX_Imm, Adder2Out, EM_Adder2Out,
//Result, EM_Result, EM_WriteData, Read_Data, MW_Read_Data, WriteData);

