`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/25/2023 10:51:54 AM
// Design Name: 
// Module Name: Branch_unit
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

module Branch_unit(
   input [2:0] Funct3,
   input [63:0] ReadData1,
   input [63:0] ReadData2,
   output reg addermuxselect
  );
  
  initial
    begin
      addermuxselect = 1'b0;
    end
  
  always @(*)
	begin
      case (Funct3)
        3'b000:
          begin
            if (ReadData1 == ReadData2)
              addermuxselect = 1'b1;
            else
              addermuxselect = 1'b0;
            end
         3'b100:
    		begin
              if (ReadData1 < ReadData2)
              addermuxselect = 1'b1;
            else
              addermuxselect = 1'b0;
            end
        3'b101:
          begin
            if (ReadData1 > ReadData2)
          	addermuxselect = 1'b1;
           else
              addermuxselect = 1'b0;
          end    
      endcase
     end
endmodule
