`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2023 09:12:45 AM
// Design Name: 
// Module Name: ALU_Control
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

module ALU_Control(
    input [1:0] ALUOp,
    input [3:0] Funct,
    output reg [3:0] Operation
    );
    
    always @ (ALUOp or Funct)
	begin
		case(ALUOp)
			2'b00: // I Type
			begin
			case(Funct[2:0])
				4'b001: Operation = 4'b1000; // SLLI
				default: Operation = 4'b0010; // I - Type (ld, sd)
			endcase
			end
			2'b01: Operation = 4'b0110; // SB Type (Beq)
			2'b10: // R Type 
			begin 
			case(Funct)
				4'b0000: Operation = 4'b0010;
				4'b1000: Operation = 4'b0110;
				4'b0111: Operation = 4'b0000;
				4'b0110: Operation = 4'b0001;
			endcase
			end
		endcase
	end
endmodule
