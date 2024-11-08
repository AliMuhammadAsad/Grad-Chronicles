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
    output [63:0] imm_data
    );
wire [11:0] load, store, cond; //12-bit data to be extended
reg [11:0] q; wire [51:0] ext;
assign ext = {52{instruction[31]}};
assign load = instruction[31:20];
assign store = {instruction[31:25], instruction[11:7]};
assign cond = {instruction[31], instruction[7], instruction[30:25], instruction[11:8]};
always @(instruction or q) begin
    case(instruction[6:5])
        00 : q = load;
        01 : q = store;
        10 : q = cond;
        11 : q = cond;
    endcase
end
assign imm_data = {ext, q};
endmodule



//always@* begin
//if (instruction[6:5]== 2'b10 || instruction[5:4] == 2'b11)
//    assign data = {instruction[31], instruction[7], instruction[30:25], instruction[11:8]};
//else if (instruction[6:5] == 2'b00)
//    assign data = instruction[31:20];
//else if (instruction[6:5] == 2'b01)
//    assign data = {instruction[31:25], instruction[11:7]};
//end
