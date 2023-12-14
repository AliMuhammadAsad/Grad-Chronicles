`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/06/2023 11:38:29 AM
// Design Name: 
// Module Name: testbench_parser_32
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


module testbench_parser_32();
reg [31:0] instruction;
wire [6:0] opcode; wire [6:0] funct7; 
wire [4:0] rd, rs1, rs2; wire [2:0] funct3;

inst_parser_32 ip1(instruction, opcode, rd, funct3, rs1, rs2, funct7); 

initial begin
instruction = 32'h00730533; // 0000000 00111 00110 000 01010 0110011 opcode = 0110011 rd = 01010 funct3 = 000 rs1 = 00110 rs2 = 00111 funct7 = 0000000
$display(opcode);
#100 instruction = 32'h1002a503; 
//$display(instruction, opcode, rd, funct3, rs1, rs2, funct7);
#100 instruction = 32'h00040263; 
//$display(instruction, opcode, rd, funct3, rs1, rs2, funct7);
#100 instruction = 32'h000;
//$display(instruction, opcode, rd, funct3, rs1, rs2, funct7);

end
endmodule
