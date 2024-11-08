`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/06/2023 11:13:33 AM
// Design Name: 
// Module Name: testbench_mux_2x1_64
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


module testbench_mux_2x1_64();
reg S;
reg [63:0] A, B; 
wire [63:0] Y;
    
mux_2x1_64 m1(A, B, S, Y);
initial begin
A = 64'h0000000000000001;
B = 64'hFFFFFFFFFFFFFFFF;
S = 0;

#100 S = 1;
#100 S = 0;
#100 S = 1;
#100 S = 0;

end
endmodule
