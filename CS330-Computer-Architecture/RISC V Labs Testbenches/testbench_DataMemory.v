`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/27/2023 11:24:23 AM
// Design Name: 
// Module Name: testbench_DataMemory
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


module testbench_DataMemory();

reg [63:0] Mem_Addr, Write_Data; reg clk, MemWrite, MemRead;
wire [63:0] Read_Data;

Data_Memory dm1(Mem_Addr, Write_Data, clk, MemWrite, MemRead, Read_Data);

initial begin
clk = 0;
Mem_Addr = 0; Write_Data = 64'b01010101111100; MemWrite = 0; MemRead = 0;

#50 MemWrite = 0; MemRead = 1;
#50 MemWrite = 1; MemRead = 0;
#50 MemWrite = 0; MemRead = 1;
#50 MemWrite = 1; MemRead = 1;
#50 MemWrite = 1; MemRead = 1; 

end


always
    #5 clk = ~clk;

endmodule
