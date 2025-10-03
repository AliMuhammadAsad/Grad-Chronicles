`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/06/2023 12:48:24 PM
// Design Name: 
// Module Name: testbench_ide
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

module testbench_ide();
    
    reg [31:0] instruction; 
    wire [63:0] imm_data;
    im_data_extract ide1(instruction, imm_data );
    initial begin
        instruction = 32'b01010100101010101001010101010011;
        #100 instruction = 32'h1002a503; 
        #100 instruction = 32'h00040263; 
        #100 instruction = 32'h000;       
    end
endmodule


//module testbench_ide();
//reg [31:0] instruction; wire [63:0] imm_data;

//im_data_extract ide1(instruction, imm_data);
//initial begin
//instruction = 32'h00730533;
//#100 instruction = 32'h1002a503; 
//#100 instruction = 32'h00040263; 
//#100 instruction = 32'h000;
//end
//endmodule
