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

reg [7:0] registers [15:0]; //Initialising 16 registers of 8-bits
integer i;
initial begin //Storing dummy data in the registers
//Each register of 8-bits
for (i = 0; i < 16; i = i + 1) begin
 registers[i] = 8'd0 + i;
end
end

always @(posedge clk)
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
end
end

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
