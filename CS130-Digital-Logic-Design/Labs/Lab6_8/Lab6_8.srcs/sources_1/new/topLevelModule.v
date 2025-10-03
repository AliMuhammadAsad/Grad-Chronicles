`timescale 1ns / 1ps
module topLevelModule(
    input [1:0] S,
    input [3:0] A,
    input [3:0] B,
    input [3:0] C,
    input [3:0] D,
    output [6:0] Y,
    input En,
    output EnA,
    output EnB,
    output EnC,
    output EnD
    );
wire [3:0] Mux_out;

mux_4_1 m1(S, A, B, C, D, Mux_out);
segment_decoder sd1(Mux_out, Y);
DeMux dm1(S, En, EnA, EnB, EnC, EnD);

endmodule
