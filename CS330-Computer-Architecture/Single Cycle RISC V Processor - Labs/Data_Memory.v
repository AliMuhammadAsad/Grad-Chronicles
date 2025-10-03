`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2023 11:13:47 AM
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
    input [63:0] Mem_Addr,
    input [63:0] Write_Data,
    input clk,
    input MemWrite,
    input MemRead,
    output reg [63:0] Read_Data
    );

reg [7:0] registers [63:0]; //Initialising 16 registers of 8-bits
//integer i;
//initial begin //Storing dummy data in the registers
////Each register of 8-bits
//for (i = 0; i < 64; i = i + 1) begin
// registers[i] = 8'd0 + i;
//end
//end

initial
	begin
		registers[0] = 8'd10;
		registers[1] = 8'd0;
		registers[2] = 8'd0;
		registers[3] = 8'd0;
		registers[4] = 8'd0;
		registers[5] = 8'd0;
		registers[6] = 8'd0;
		registers[7] = 8'd0;
		registers[8] = 8'd8;
		registers[9] = 8'd9;
		registers[10] = 8'd10;
		registers[11] = 8'd11;
		registers[12] = 8'd12;
		registers[13] = 8'd13;
		registers[14] = 8'd14;
		registers[15] = 8'd15;
		registers[16] = 8'd16;
		registers[17] = 8'd17;
		registers[18] = 8'd18;
		registers[19] = 8'd19;
		registers[20] = 8'd20;
		registers[21] = 8'd21;
		registers[22] = 8'd22;
		registers[23] = 8'd23;
		registers[24] = 8'd24;
		registers[25] = 8'd25;
		registers[26] = 8'd26;
		registers[27] = 8'd27;
		registers[28] = 8'd28;
		registers[29] = 8'd29;
		registers[30] = 8'd30;
		registers[31] = 8'd31;
		registers[32] = 8'd0;
		registers[33] = 8'd1;
		registers[34] = 8'd2;
		registers[35] = 8'd3;
		registers[36] = 8'd4;
		registers[37] = 8'd5;
		registers[38] = 8'd6;
		registers[39] = 8'd7;
		registers[40] = 8'd8;
		registers[41] = 8'd9;
		registers[42] = 8'd0;
		registers[43] = 8'd0;
		registers[44] = 8'd0 ;
		registers[45] = 8'd0;
		registers[46] = 8'd0;
		registers[47] = 8'd0;
		registers[48] = 8'd0;
		registers[49] = 8'd0;
		registers[50] = 8'd0;
		registers[51] = 8'd0;
		registers[52] = 8'd0;
		registers[53] = 8'd0;
		registers[54] = 8'd0;
		registers[55] = 8'd0;
		registers[56] = 8'd0;
		registers[57] = 8'd0;
		registers[58] = 8'd0;
		registers[59] = 8'd0;
		registers[60] = 8'd0;
		registers[61] = 8'd0;
		registers[62] = 8'd0;
		registers[63] = 8'd0;
	end

always @(*)
begin
if(MemWrite == 1) begin
    registers[Mem_Addr + 7] = Write_Data[63:56];
    registers[Mem_Addr + 6] = Write_Data[55:48];
    registers[Mem_Addr + 5] = Write_Data[47:40];
    registers[Mem_Addr + 4] = Write_Data[39:32];
    registers[Mem_Addr + 3] = Write_Data[31:24];
    registers[Mem_Addr + 2] = Write_Data[23:16];
    registers[Mem_Addr + 1] = Write_Data[15:8];
    registers[Mem_Addr + 0] = Write_Data[7:0] ;
end end

always @(*) begin
if(MemRead == 1) begin
    Read_Data = {registers[Mem_Addr + 7],
    registers[Mem_Addr + 6],
    registers[Mem_Addr + 5],
    registers[Mem_Addr + 4],
    registers[Mem_Addr + 3],
    registers[Mem_Addr + 2],
    registers[Mem_Addr + 1],
    registers[Mem_Addr]};
end
end

endmodule
