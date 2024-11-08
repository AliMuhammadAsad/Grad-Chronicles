`timescale 1ns / 1ps

module mux_4_1(
    input [1:0] S,
    input [3:0] A,
    input [3:0] B,
    input [3:0] C,
    input [3:0] D,
    output [3:0] Y
    );
assign Y[3:0] = (S == 2'b00) ? A[3:0] : (S == 2'b01) ? B[3:0] : (S == 2'b10) ? C[3:0] : D[3:0];
endmodule
