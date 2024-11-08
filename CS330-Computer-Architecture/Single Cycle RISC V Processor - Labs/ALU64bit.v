`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/15/2023 10:56:57 PM
// Design Name: 
// Module Name: ALU64bit
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


module ALU64bit(
    input [63:0] a,
    input [63:0] b,
    input CarryIn,
    input [3:0] ALUOp,
    output reg [63:0] Result,
    output reg CarryOut,
    output reg Zero
    );

always @(*) begin
    case (ALUOp)
        4'b0000: Result = a & b;
        4'b0001: Result = a | b;
        4'b0010: Result = a + b;
        4'b0110: Result = a - b;
        4'b1100: Result = ~(a | b);
    endcase
    if (Result == 64'd0) Zero = 1'b1;
    else Zero = 1'b0;
    CarryOut = CarryIn && 1'b0;
end
endmodule


//    wire c0, c1, c2, c3, c4, c5, c6;
    
//    ALU_8bit alu0(a[7:0], b[7:0], CarryIn, ALUop, Result[7:0], c0);
//    ALU_8bit alu1(a[15:8], b[15:8], c0, ALUop, Result[15:8], c1);
//    ALU_8bit alu2(a[23:16], b[23:16], c1, ALUop, Result[23:16], c2);
//    ALU_8bit alu3(a[31:24], b[31:24], c2, ALUop, Result[31:24], c3);
//    ALU_8bit alu4(a[39:32], b[39:32], c3, ALUop, Result[39:32], c4);
//    ALU_8bit alu5(a[47:40], b[47:40], c4, ALUop, Result[47:40], c5);
//    ALU_8bit alu6(a[55:48], b[55:48], c5, ALUop, Result[55:48], c6);
//    ALU_8bit alu7(a[63:56], b[63:56], c6, ALUop, Result[63:56], CarryOut);
    
//    always @(*)
//    begin
//    if(Result == 64'd0)begin assign Zero = 1'b1; end
//    else begin assign Zero = 1'b0; end
//    end