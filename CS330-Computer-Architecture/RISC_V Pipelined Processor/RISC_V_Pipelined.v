`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2023 08:06:57 PM
// Design Name: 
// Module Name: RISC_V_Pipelined
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

module RISC_V_Pipelined(
    input clk,
    input reset
    );
// Declaration of all necessary wires // 
wire [63:0] PC_In, PC_Out, Adder1Out, Adder2Out, Imm, WriteData, ReadData1, ReadData2, Result, Read_Data;
wire [63:0] MuxmidOut;
wire [31:0] Instruction;
wire [6:0] Opcode, Funct7;
wire [4:0] RD, RS1, RS2;
wire [3:0] Funct, Operation;
wire [2:0] Funct3;
wire [1:0] ALUOp;
wire Branch, MemRead, MemWrite, MemtoReg, RegWrite, ALUSrc, Zero, sel_Branch;

wire [63:0] IFID_PC_Out;
wire [31:0] IFID_Instruction;

wire IDEX_Branch, IDEX_MemRead, IDEX_MemWrite, IDEX_MemtoReg, IDEX_RegWrite, IDEX_ALUSrc,
EM_Branch, EM_MemRead, EM_MemWrite, EM_MemtoReg, EM_RegWrite, EM_Zero,
MW_MemtoReg, MW_RegWrite;
wire [1:0] IDEX_ALUOp;
wire [3:0] IDEX_Funct;
wire [4:0] IDEX_RS1, IDEX_RS2, IDEX_RD, EM_RD, MW_RD;
wire [63:0] IDEX_PC_Out, IDEX_ReadData1, IDEX_ReadData2, IDEX_Imm,
            EM_Adder2Out, EM_Result, EM_WriteData, MW_Result, MW_Read_Data;

// --------------------------------------------------------------------- //
// Stage 1 - Instruction Fetch //
Mux_2x1 muxfirst(.A(Adder1Out), .B(EM_Adder2Out), .S(sel_Branch), .Out(PC_In)); 
Program_Counter PC(.clk(clk), .reset(reset), .PC_In(PC_In), .PC_Out(PC_Out));
Adder add1(.A(PC_Out), .B(64'd4), .Out(Adder1Out));
Instruction_Memory IM(.Inst_Address(PC_Out), .Instruction(Instruction));
IF_ID ifid(.clk(clk), .reset(reset), .Instruction(Instruction), .PC_Out(PC_Out), .IFID_Instruction(IFID_Instruction), .IFID_PC_Out(IFID_PC_Out));

// Stage 2 - Instruction Decode //
Instruction_Parser IP(.Instruction(IFID_Instruction), .Opcode(Opcode), .RD(RD), .Funct3(Funct3), .RS1(RS1), .RS2(RS2), .Funct7(Funct7));
Control_Unit CU(.Opcode(Opcode), .ALUOp(ALUOp), .Branch(Branch), .MemRead(MemRead), .MemtoReg(MemtoReg), .MemWrite(MemWrite), .ALUSrc(ALUSrc), .RegWrite(RegWrite));
Imm_Gen IG(.Instruction(IFID_Instruction), .Imm(Imm));
RegisterFile RF(.clk(clk), .reset(reset), .WriteData(WriteData), .RS1(RS1), .RS2(RS2), .RD(MW_RD), .RegWrite(MW_RegWrite), .ReadData1(ReadData1), .ReadData2(ReadData2));
assign Funct = {IFID_Instruction[30], IFID_Instruction[14:12]};
ID_EX idex(.clk(clk), .reset(reset), .Branch(Branch), .MemRead(MemRead), .MemWrite(MemWrite), .MemtoReg(MemtoReg), .RegWrite(RegWrite), .ALUSrc(ALUSrc), .ALUOp(ALUOp),
        .Funct(Funct), .RS1(RS1), .RS2(RS2), .RD(RD), .IFID_PC_Out(IFID_PC_Out), .ReadData1(ReadData1), .ReadData2(ReadData2), .Imm(Imm),
        .IDEX_Branch(IDEX_Branch), .IDEX_MemRead(IDEX_MemRead), .IDEX_MemWrite(IDEX_MemWrite), .IDEX_MemtoReg(IDEX_MemtoReg), .IDEX_RegWrite(IDEX_RegWrite), .IDEX_ALUSrc(IDEX_ALUSrc),
        .IDEX_ALUOp(IDEX_ALUOp), .IDEX_Funct(IDEX_Funct), .IDEX_RS1(IDEX_RS1), .IDEX_RS2(IDEX_RS2), .IDEX_RD(IDEX_RD),
        .IDEX_PC_Out(IDEX_PC_Out), .IDEX_ReadData1(IDEX_ReadData1), .IDEX_ReadData2(IDEX_ReadData2), .IDEX_Imm(IDEX_Imm));

// Stage 3 - Execution // 
Adder add2(.A(IDEX_PC_Out), .B(IDEX_Imm << 1), .Out(Adder2Out));
Mux_2x1 muxmid(.A(IDEX_ReadData2), .B(IDEX_Imm), .S(IDEX_ALUSrc), .Out(MuxmidOut));
ALU_Control AluC(.ALUOp(IDEX_ALUOp), .Funct(IDEX_Funct), .Operation(Operation));
ALU64bit ALU(.A(IDEX_ReadData1), .B(MuxmidOut), .ALUOp(Operation), .Result(Result), .Zero(Zero));
EX_MEM EM(.clk(clk), .reset(reset), .Branch(IDEX_Branch), .MemRead(IDEX_MemRead), .MemWrite(IDEX_MemWrite), .MemtoReg(IDEX_MemtoReg), .RegWrite(IDEX_RegWrite),
        .Zero(Zero), .RD(IDEX_RD), .Adder2Out(Adder2Out), .Result(Result), .WriteData(WriteData), 
        .EM_Branch(EM_Branch), .EM_MemRead(EM_MemRead), .EM_MemWrite(EM_MemWrite), .EM_MemtoReg(EM_MemtoReg), .EM_RegWrite(EM_RegWrite), .EM_Zero(EM_Zero), .EM_RD(EM_RD), .EM_Adder2Out(EM_Adder2Out), .EM_Result(EM_Result), .EM_WriteData(EM_WriteData));

// Stage 4 - Memory Access // 
assign sel_Branch = EM_Branch && EM_Zero;
Data_Memory DM(.clk(clk), .MemWrite(EM_MemWrite), .MemRead(EM_MemRead), .Mem_Addr(EM_Result), .Write_Data(EM_WriteData), .Read_Data(Read_Data));
MEM_WB MW(.clk(clk), .reset(reset), .MemtoReg(EM_MemtoReg), .RegWrite(EM_RegWrite), .RD(EM_RD), .EM_Result(EM_Result), .Read_Data(Read_Data), 
        .MW_MemtoReg(MW_MemtoReg), .MW_RegWrite(MW_RegWrite), .MW_RD(MW_RD), .MW_Result(MW_Result), .MW_Read_Data(MW_Read_Data));

// Stage 5 - Write Back //
Mux_2x1 muxlast(.A(MW_Read_Data), .B(MW_Result), .S(MW_MemtoReg), .Out(WriteData));
endmodule


//module RISC_V_Pipelined(
//    input clk,
//    input reset,
//    output reg [4:0] RD, RS1, RS2, IDEX_RD, IDEX_RS1, IDEX_RS2, EM_RD, MW_RD,
//    output reg[6:0] Opcode,
//    output reg [31:0] Instruction, IFID_Instruction,
//    output reg [63:0] PC_Out, IFID_PC_Out, ReadData1, ReadData2, IDEX_ReadData1, IDEX_ReadData2, Imm, IDEX_Imm,
//    Adder2Out, EM_Adder2Out, Result, EM_Result, EM_WriteData, Read_Data, MW_Read_Data, WriteData
//    );