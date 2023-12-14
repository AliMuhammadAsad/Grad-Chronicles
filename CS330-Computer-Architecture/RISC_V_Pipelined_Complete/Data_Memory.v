`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 10:55:43 AM
// Design Name: 
// Module Name: Data_Memory
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

module Data_Memory(
    input clk,
    input MemWrite,
    input MemRead,
    input [63:0] Mem_Addr,
    input [63:0] Write_Data,
    output reg [63:0] Read_Data,
    //
	output [63:0] index0,
    output [63:0] index1,
    output [63:0] index2,
    output [63:0] index3,
    output [63:0] index4
    );

    reg [7:0] DataMemory [63:0];


	integer i;
  initial
    begin
      for (i=0; i<64; i=i+1)
        begin
          DataMemory[i] = 0;
    
        end
      DataMemory[0] = 8'd5;
      DataMemory[8] = 8'd2;
      DataMemory[16] = 8'd1;
      DataMemory[24] = 8'd7;
      DataMemory[32] = 8'd4;
    end
	
  assign index0 = {DataMemory[7],DataMemory[6],DataMemory[5],DataMemory[4],DataMemory[3],DataMemory[2],DataMemory[1],DataMemory[0]};
  assign index1 = {DataMemory[15],DataMemory[14],DataMemory[13],DataMemory[12],DataMemory[11],DataMemory[10],DataMemory[9],DataMemory[8]};
  assign index2 = {DataMemory[23],DataMemory[22],DataMemory[21],DataMemory[20],DataMemory[19],DataMemory[18],DataMemory[17],DataMemory[16]};
  assign index3 = {DataMemory[31],DataMemory[30],DataMemory[29],DataMemory[28],DataMemory[27],DataMemory[26],DataMemory[25],DataMemory[24]};
  assign index4 = {DataMemory[39],DataMemory[38],DataMemory[37],DataMemory[36],DataMemory[35],DataMemory[34],DataMemory[33],DataMemory[32]};
  
	
	always @ (*)
	begin
		if (MemRead)
			Read_Data = {DataMemory[Mem_Addr+7],DataMemory[Mem_Addr+6],DataMemory[Mem_Addr+5],DataMemory[Mem_Addr+4],DataMemory[Mem_Addr+3],DataMemory[Mem_Addr+2],DataMemory[Mem_Addr+1],DataMemory[Mem_Addr]};
	end
	
	always @ (posedge clk)
	begin
		if (MemWrite)
		begin
			DataMemory[Mem_Addr] = Write_Data[7:0];
			DataMemory[Mem_Addr+1] = Write_Data[15:8];
			DataMemory[Mem_Addr+2] = Write_Data[23:16];
			DataMemory[Mem_Addr+3] = Write_Data[31:24];
			DataMemory[Mem_Addr+4] = Write_Data[39:32];
			DataMemory[Mem_Addr+5] = Write_Data[47:40];
			DataMemory[Mem_Addr+6] = Write_Data[55:48];
			DataMemory[Mem_Addr+7] = Write_Data[63:56];
		end
	end

endmodule

//reg [7:0] registers [63:0]; //Initialising 16 registers of 8-bits

//initial
//	begin
//	    registers[0] = 8'd0; registers[1] = 8'd0; registers[2] = 8'd0;
//		registers[3] = 8'd0; registers[4] = 8'd0; registers[5] = 8'd0;
//		registers[6] = 8'd0; registers[7] = 8'd0; registers[8] = 8'd0;
//		registers[9] = 8'd0; registers[10] = 8'd0; registers[11] = 8'd0;
//		registers[12] = 8'd0; registers[13] = 8'd0; registers[14] = 8'd0;
//		registers[15] = 8'd0; registers[16] = 8'd0; registers[17] = 8'd0;
//		registers[18] = 8'd0; registers[19] = 8'd0; registers[20] = 8'd0;
//		registers[21] = 8'd0; registers[22] = 8'd0; registers[23] = 8'd0;
//		registers[24] = 8'd0; registers[25] = 8'd0; registers[26] = 8'd0;
//		registers[27] = 8'd0; registers[28] = 8'd0; registers[29] = 8'd0;
//		registers[30] = 8'd0; registers[31] = 8'd0; registers[32] = 8'd0;
//		registers[33] = 8'd0; registers[34] = 8'd0; registers[35] = 8'd0;
//		registers[36] = 8'd0; registers[37] = 8'd0; registers[38] = 8'd0;
//		registers[39] = 8'd0; registers[40] = 8'd0; registers[41] = 8'd0;
//		registers[42] = 8'd0; registers[43] = 8'd0; registers[44] = 8'd0;
//		registers[45] = 8'd0; registers[46] = 8'd0; registers[47] = 8'd0;
//		registers[48] = 8'd0; registers[49] = 8'd0; registers[50] = 8'd0;
//		registers[51] = 8'd0; registers[52] = 8'd0; registers[53] = 8'd0;
//		registers[54] = 8'd0; registers[55] = 8'd0; registers[56] = 8'd0;
//		registers[57] = 8'd0; registers[58] = 8'd0; registers[59] = 8'd0;
//		registers[60] = 8'd0; registers[61] = 8'd0; registers[62] = 8'd0;
//		registers[63] = 8'd0;
//	end

//always @(*)
//begin
//if(MemWrite == 1) begin
//    registers[Mem_Addr + 7] = Write_Data[63:56];
//    registers[Mem_Addr + 6] = Write_Data[55:48];
//    registers[Mem_Addr + 5] = Write_Data[47:40];
//    registers[Mem_Addr + 4] = Write_Data[39:32];
//    registers[Mem_Addr + 3] = Write_Data[31:24];
//    registers[Mem_Addr + 2] = Write_Data[23:16];
//    registers[Mem_Addr + 1] = Write_Data[15:8];
//    registers[Mem_Addr + 0] = Write_Data[7:0] ;
//end end

//always @(*) begin
//if(MemRead == 1) begin
//    Read_Data = {registers[Mem_Addr + 7],
//    registers[Mem_Addr + 6],
//    registers[Mem_Addr + 5],
//    registers[Mem_Addr + 4],
//    registers[Mem_Addr + 3],
//    registers[Mem_Addr + 2],
//    registers[Mem_Addr + 1],
//    registers[Mem_Addr]};
//end
//end