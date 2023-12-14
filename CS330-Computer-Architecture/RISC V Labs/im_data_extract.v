`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/06/2023 12:13:44 PM
// Design Name: 
// Module Name: im_data_extract
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

module im_data_extract(
    input [31:0] instruction,
    output reg [63:0] imm_data
    );
reg [11:0] data; //12-bit data to be extended

always@* begin
if (instruction[6:5]== 2'b10 || instruction[5:4] == 2'b11)
    assign data = {instruction[31], instruction[7], instruction[30:25], instruction[11:8]};
else if (instruction[6:5] == 2'b00)
    assign data = instruction[31:20];
else if (instruction[6:5] == 2'b01)
    assign data = {instruction[31:25], instruction[11:7]};
end

always@* 
begin
    imm_data <= $unsigned(data);
end
endmodule
