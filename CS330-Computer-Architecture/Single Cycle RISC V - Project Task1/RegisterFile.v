`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2023 09:12:45 AM
// Design Name: 
// Module Name: RegisterFile
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

module RegisterFile(
    input clk,
    input reset,
    input [63:0] WriteData,
    input [4:0] RS1,
    input [4:0] RS2,
    input [4:0] RD,
    input RegWrite,
    output reg [63:0] ReadData1,
    output reg [63:0] ReadData2
    );
    
reg[63:0] Registers [31:0];    //initialize Registers with random values (using 'initial' block)
integer i;
  initial
    begin
      for (i=0; i<31; i=i+1)
        begin
          Registers[i] = 0;
        end
    end
 //operation of writing data into a Register should always be done when  
 //positive edge of clock and RegWrite signal is asserted (or set, i.e. High)  
  always @ (posedge clk) 
    begin   
      case(RegWrite)                             
        1'b1: Registers[RD] <= WriteData;   
      endcase  
    end 
 
  always @ (*)  
    begin   
      if(reset)  
        begin    
          ReadData1 = 64'b0;    
          ReadData2 = 64'b0;   
        end   
      else   
        begin    
          ReadData1 = Registers[RS1];    
          ReadData2 = Registers[RS2];   
        end  
    end  
//reg [63:0] registers [31:0];
//integer i;
//initial begin
//for (i = 0; i < 32; i = i + 1) begin
//    registers[i] = 0;
//    end end

//always @(posedge clk) begin
//    if (RegWrite == 1) registers[RD] <= WriteData;
//end 
//always @(*) begin
//    if (reset == 1) begin
//        ReadData1 = 64'd0; ReadData2 = 64'd0; end
//    else begin
//        ReadData1 = registers[RS1]; ReadData2 = registers[RS2]; 
//    end
//end
endmodule