`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2023 10:55:43 AM
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
//    input clk,
//    input reset,
    input [63:0] A,
    input [63:0] Out,
    input [63:0] EM_Result,
    input [63:0] B,
    input MW_RegWrite,
    input [4:0] MW_RD,
    input [4:0] EM_RD,
    input [4:0] IDEX_RS1,
    input [4:0] IDEX_RS2,
    input EM_RegWrite,
    input ALUSrc,
    input [63:0] IDEX_Imm,
    input [3:0] ALUOp,
    output reg [1:0] ForwardA,
    output reg [1:0] ForwardB,
//    output reg [63:0] mux1out,
//    output reg [63:0] mux2out,
//    output reg [63:0] mux3out,
    output reg [63:0] Result,
    output reg Zero
    );
    
    reg Forward_A;
    reg Forward_B;
    reg mux1out;
    reg mux2out;
    reg mux3out;
    
always @(*) begin

    //EX Hazard
    assign Forward_A= 2'b00;
    assign Forward_B= 2'b00;
    if (EM_RegWrite)
        begin
            if ((EM_RD != 0) & (EM_RD == IDEX_RS1))
                begin
                     assign Forward_A = 2'b10;
                end
            if ((EM_RD != 0) & (EM_RD == IDEX_RS2))
                begin
                    assign Forward_B = 2'b10;
                end
        end
        
    // MEM Hazard
    if (MW_RegWrite)
        begin
            if ((MW_RD != 0) & (EM_RegWrite == 0 & EM_RD == 0) & (EM_RD != IDEX_RS1) & (MW_RD == IDEX_RS1))
                begin
                    assign Forward_A = 2'b01;
                end
            if ((MW_RD != 0) & (EM_RegWrite == 0 & EM_RD == 0) & (EM_RD != IDEX_RS2) & (MW_RD == IDEX_RS2))
                begin
                    assign Forward_B = 2'b01;
                end
        end   
    if (EM_RegWrite == 0 & MW_RegWrite == 0)
        begin 
            assign Forward_A = 2'b00;
            assign Forward_B = 2'b00;
        end   
        
     //Forward_A  
    case(Forward_A)
        2'b00: mux1out = A;   
        2'b01: mux1out = Out;
        2'b10: mux1out = EM_Result;
    endcase  
    
    //Forward_B
    case(Forward_B)
        2'b00: mux2out = B;   
        2'b01: mux2out = Out;
        2'b10: mux2out = EM_Result;
    endcase  
    
    //Mux3 to check 2nd operand of ALU is immediate data or is coming from Mux2
    if (ALUSrc)
        mux3out = IDEX_Imm;
    else
        mux3out = mux2out;
        
    //Result
    case (ALUOp)
        4'b0000: Result = mux1out & mux3out;
        4'b0001: Result = mux1out | mux3out;
        4'b0010: Result = mux1out + mux3out;
        4'b0110: Result = mux1out - mux3out;
        4'b1100: Result = ~(mux1out | mux3out);
    endcase

    if (Result == 64'd0) Zero = 1'b1;
    else Zero = 1'b0;
end
endmodule


//module ALU64bit(
//    input [63:0] A,
//    input [63:0] B,
//    input [3:0] ALUOp,
//    output reg [63:0] Result,
//    output reg Zero
//    );
    
//always @(*) begin
//    case (ALUOp)
//        4'b0000: Result = A & B;
//        4'b0001: Result = A | B;
//        4'b0010: Result = A + B;
//        4'b0110: Result = A - B;
//        4'b1100: Result = ~(A | B);
//        4'b1000: Result = A * (2 ** B); // SLLI
//        default: Result = 0;
//    endcase
//    if (Result == 64'd0) Zero = 1'b1;
//    else Zero = 1'b0;
//end
//endmodule