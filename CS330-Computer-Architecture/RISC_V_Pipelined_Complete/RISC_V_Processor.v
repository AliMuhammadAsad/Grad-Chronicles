`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 11:01:02 AM
// Design Name: 
// Module Name: RISC_V_Processor
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

module RISC_V_Processor(
    input clk,
    input reset,
    output reg [4:0] RD, RS1, RS2, IDEX_RD, IDEX_RS1, IDEX_RS2, EM_RD, MW_RD,
    output reg IDEX_MemRead, EM_MemRead,
    output reg[6:0] Opcode,
    output reg stall,
    output reg Branch, EM_Branch, MemRead, MemWrite, MemtoReg, RegWrite, ALUSrc,
    output reg [1:0] ALUOp,
    output reg [31:0] Instruction, IFID_Instruction,
    output reg [63:0] PC_In,
    output reg [63:0] PC_Out, IFID_PC_Out, ReadData1, ReadData2, IDEX_ReadData1, IDEX_ReadData2, Imm, IDEX_Imm,
    Adder2Out, EM_Adder2Out, Result, EM_Result, EM_WriteData, Read_Data, MW_Read_Data, WriteData, 
    output reg [63:0] index0, index1, index2, index3, index4
    );
// Declaration of all necessary wires // 
wire [63:0] PC_In, PC_Out, Adder1Out, Adder2Out, Imm, WriteData, ReadData1, ReadData2, Result, Read_Data;
wire [63:0] Muxmid1Out, Muxmid2Out, MuxmidOut;
wire [31:0] Instruction;
wire [6:0] Opcode, Funct7;
wire [4:0] RD, RS1, RS2;
wire [3:0] Funct, Operation;
wire [2:0] Funct3;
wire [1:0] ALUOp;
wire Branch, MemRead, MemWrite, MemtoReg, RegWrite, ALUSrc, Zero, sel_Branch, stall;
wire addermuxselect, EM_addermuxselect;

wire [63:0] IFID_PC_Out;
wire [31:0] IFID_Instruction;

wire IDEX_Branch, IDEX_MemRead, IDEX_MemWrite, IDEX_MemtoReg, IDEX_RegWrite, IDEX_ALUSrc,
EM_Branch, EM_MemRead, EM_MemWrite, EM_MemtoReg, EM_RegWrite, EM_Zero,
MW_MemtoReg, MW_RegWrite, PC_Write, IFID_Write, IDEX_MuxOut;
wire [1:0] IDEX_ALUOp, ForwardA, ForwardB;
wire [3:0] IDEX_Funct;
wire [4:0] IDEX_RS1, IDEX_RS2, IDEX_RD, EM_RD, MW_RD;
wire [63:0] IDEX_PC_Out, IDEX_ReadData1, IDEX_ReadData2, IDEX_Imm,
            EM_Adder2Out, EM_Result, EM_WriteData, MW_Result, MW_Read_Data,
            mux1out, mux2out, mux3out;
wire [63:0] index0, index1, index2, index3, index4;

// --------------------------------------------------------------------- //
// Stage 1 - Instruction Fetch //
Mux_2x1 muxfirst(.A(Adder1Out), .B(EM_Adder2Out), .S(sel_Branch), .Out(PC_In)); 
Program_Counter PC(.clk(clk), .reset(reset), .stall(stall), .PC_In(PC_In), .PC_Out(PC_Out));
Adder add1(.A(PC_Out), .B(64'd4), .Out(Adder1Out));
Instruction_Memory IM(.Inst_Address(PC_Out), .Instruction(Instruction));
IF_ID ifid(.clk(clk), .reset(reset), .stall(stall), .Instruction(Instruction), .PC_Out(PC_Out), .IFID_Instruction(IFID_Instruction), .IFID_PC_Out(IFID_PC_Out));
Hazard_Detection_Unit HDU(.RS1(RS1), .RS2(RS2), .IDEX_RD(IDEX_RD), .IDEX_MemRead(IDEX_MemRead), .stall(stall)); // .IFID_Write(IFID_Write), .PC_Write(PC_Write), .IDEX_MuxOut(IDEX_MuxOut), 

// Stage 2 - Instruction Decode //
Instruction_Parser IP(.Instruction(IFID_Instruction), .Opcode(Opcode), .RD(RD), .Funct3(Funct3), .RS1(RS1), .RS2(RS2), .Funct7(Funct7));
Control_Unit CU(.Opcode(Opcode), .stall(stall), .ALUOp(ALUOp), .Branch(Branch), .MemRead(MemRead), .MemtoReg(MemtoReg), .MemWrite(MemWrite), .ALUSrc(ALUSrc), .RegWrite(RegWrite));
Imm_Gen IG(.Instruction(IFID_Instruction), .Imm(Imm));
RegisterFile RF(.clk(clk), .reset(reset), .WriteData(WriteData), .RS1(RS1), .RS2(RS2), .RD(MW_RD), .RegWrite(MW_RegWrite), .ReadData1(ReadData1), .ReadData2(ReadData2));
assign Funct = {IFID_Instruction[30], IFID_Instruction[14:12]};

//assign Branch = IDEX_MuxOut ? 0 : Branch;
//assign MemRead = IDEX_MuxOut ? 0 : MemRead;
//assign MemWrite = IDEX_MuxOut ? 0 : MemWrite;
//assign MemtoReg = IDEX_MuxOut ? 0 : MemtoReg ;
//assign RegWrite = IDEX_MuxOut ? 0 : RegWrite ;
//assign ALUSrc = IDEX_MuxOut ? 0 : ALUSrc ;
//assign ALUOp = IDEX_MuxOut ? 2'b00 : ALUOp ;

ID_EX idex(.clk(clk), .reset(reset), .Branch(Branch), .MemRead(MemRead), .MemWrite(MemWrite), .MemtoReg(MemtoReg), .RegWrite(RegWrite), .ALUSrc(ALUSrc), .ALUOp(ALUOp),
        .Funct(Funct), .RS1(RS1), .RS2(RS2), .RD(RD), .IFID_PC_Out(IFID_PC_Out), .ReadData1(ReadData1), .ReadData2(ReadData2), .Imm(Imm),
        .IDEX_Branch(IDEX_Branch), .IDEX_MemRead(IDEX_MemRead), .IDEX_MemWrite(IDEX_MemWrite), .IDEX_MemtoReg(IDEX_MemtoReg), .IDEX_RegWrite(IDEX_RegWrite), .IDEX_ALUSrc(IDEX_ALUSrc),
        .IDEX_ALUOp(IDEX_ALUOp), .IDEX_Funct(IDEX_Funct), .IDEX_RS1(IDEX_RS1), .IDEX_RS2(IDEX_RS2), .IDEX_RD(IDEX_RD),
        .IDEX_PC_Out(IDEX_PC_Out), .IDEX_ReadData1(IDEX_ReadData1), .IDEX_ReadData2(IDEX_ReadData2), .IDEX_Imm(IDEX_Imm));

// Stage 3 - Execution // 
Adder add2(.A(IDEX_PC_Out), .B(IDEX_Imm << 1), .Out(Adder2Out));
Mux_2x1 muxmid(.A(IDEX_ReadData2), .B(IDEX_Imm), .S(IDEX_ALUSrc), .Out(MuxmidOut));
ALU_Control AluC(.ALUOp(IDEX_ALUOp), .Funct(IDEX_Funct), .Operation(Operation));
//ALU64bit ALU(.A(IDEX_ReadData1), .B(MuxmidOut), .ALUOp(Operation), .Result(Result), .Zero(Zero));
Branch_unit bu(.funct3(Funct3), .readData1(ReadData1), .b(ReadData2), .addermuxselect(addermuxselect));
ALU64bit ALU(.A(IDEX_ReadData1), .Out(WriteData), .EM_Result(EM_Result), .B(ReadData2), . MW_RegWrite(MW_RegWrite), .MW_RD(MW_RD), .EM_RD(EM_RD), .IDEX_RS1(IDEX_RS1), .IDEX_RS2(IDEX_RS2), .EM_RegWrite(EM_RegWrite), .ALUSrc(ALUSrc), .IDEX_Imm(IDEX_Imm), .ALUOp(ALUOp), .ForwardA(ForwardA), .ForwardB(ForwardB), .Result(Result), .Zero(Zero));
EX_MEM EM(.clk(clk), .reset(reset), .Branch(IDEX_Branch), .MemRead(IDEX_MemRead), .MemWrite(IDEX_MemWrite), .MemtoReg(IDEX_MemtoReg), .RegWrite(IDEX_RegWrite),
        .Zero(Zero), .addermuxselect(addermuxselet), .RD(IDEX_RD), .Adder2Out(Adder2Out), .Result(Result), .WriteData(WriteData), 
        .EM_Branch(EM_Branch), .EM_MemRead(EM_MemRead), .EM_MemWrite(EM_MemWrite), .EM_MemtoReg(EM_MemtoReg), .EM_RegWrite(EM_RegWrite), .EM_Zero(EM_Zero), .EM_addermuxselect(EM_addermuxselect), .EM_RD(EM_RD), .EM_Adder2Out(EM_Adder2Out), .EM_Result(EM_Result), .EM_WriteData(EM_WriteData));

// Stage 4 - Memory Access // 
//assign sel_Branch = EM_Branch && EM_Zero;
assign sel_Branch = EM_Branch && EM_addermuxselect;
Data_Memory DM(.clk(clk), .MemWrite(EM_MemWrite), .MemRead(EM_MemRead), .Mem_Addr(EM_Result), .Write_Data(EM_WriteData), .Read_Data(Read_Data), .index0(index0), .index1(index1), .index2(index2), .index3(index3), .index4(index4));
MEM_WB MW(.clk(clk), .reset(reset), .MemtoReg(EM_MemtoReg), .RegWrite(EM_RegWrite), .RD(EM_RD), .EM_Result(EM_Result), .Read_Data(Read_Data), 
        .MW_MemtoReg(MW_MemtoReg), .MW_RegWrite(MW_RegWrite), .MW_RD(MW_RD), .MW_Result(MW_Result), .MW_Read_Data(MW_Read_Data));

// Stage 5 - Write Back //
Mux_2x1 muxlast(.A(MW_Read_Data), .B(MW_Result), .S(MW_MemtoReg), .Out(WriteData));
endmodule


//module RISC_V_Processor(
//    input clk,
//    input reset,
//    output reg [4:0] RD, RS1, RS2, IDEX_RD, IDEX_RS1, IDEX_RS2, EM_RD, MW_RD,
//    output reg[6:0] Opcode,
//    output reg [31:0] Instruction, IFID_Instruction,
//    output reg [63:0] PC_Out, IFID_PC_Out, ReadData1, ReadData2, IDEX_ReadData1, IDEX_ReadData2, Imm, IDEX_Imm,
//    Adder2Out, EM_Adder2Out, Result, EM_Result, EM_WriteData, Read_Data, MW_Read_Data, WriteData
//    );