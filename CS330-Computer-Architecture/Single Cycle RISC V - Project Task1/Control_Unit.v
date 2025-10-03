`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2023 09:12:45 AM
// Design Name: 
// Module Name: Control_Unit
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

module Control_Unit(
    input stall,
    input [6:0] Opcode,
    output reg [1:0] ALUOp,
    output reg Branch,
    output reg MemRead,
    output reg MemtoReg,
    output reg MemWrite,
    output reg ALUSrc,
    output reg RegWrite
    );

always @(*) begin
    case(Opcode)
        7'b0110011: begin //R-Format Instruction
            Branch = 1'b0; MemRead = 1'b0; MemtoReg = 1'b0; ALUOp = 2'b10;
            MemWrite = 1'b0; ALUSrc = 1'b0; RegWrite = 1'b1;
        end
        7'b0000011: begin //I-Format Instruction(ld)
            Branch = 1'b0; MemRead = 1'b1; MemtoReg = 1'b1; ALUOp = 2'b00;
            MemWrite = 1'b0; ALUSrc = 1'b1; RegWrite = 1'b1;
        end
        7'b0010011: begin //I-Type Instruction (addi)
            Branch = 1'b0; MemRead = 1'b0; MemtoReg = 1'b0; ALUOp = 2'b00;
            MemWrite = 1'b0; ALUSrc = 1'b1; RegWrite = 1'b1;
        end
        7'b0100011: begin //S-Type Instruction(sd)
            Branch = 1'b0; MemRead = 1'b0; MemtoReg = 1'bx; ALUOp = 2'b00;
            MemWrite = 1'b1; ALUSrc = 1'b1; RegWrite = 1'b0;
        end
        7'b1100011: begin //SB-Type Instruction(beq)
            Branch = 1'b1; MemRead = 1'b0; MemtoReg = 1'bx; ALUOp = 2'b01;
            MemWrite = 1'b0; ALUSrc = 1'b0; RegWrite = 1'b0;
        end
        default: begin //Default Condition
            Branch = 1'b0; MemRead = 1'b0; MemtoReg = 1'b0; ALUOp = 2'b00;
            MemWrite = 1'b0; ALUSrc = 1'b0; RegWrite = 1'b0;
        end
    endcase 
    if (stall == 1'b1) begin
        Branch = 1'b0; MemRead = 1'b0; MemtoReg = 1'b0; ALUOp = 2'b00;
        MemWrite = 1'b0; ALUSrc = 1'b0; RegWrite = 1'b0;
    end
end
endmodule
