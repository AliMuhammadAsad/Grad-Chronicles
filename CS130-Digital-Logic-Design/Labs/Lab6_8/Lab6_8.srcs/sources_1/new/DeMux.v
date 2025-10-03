`timescale 1ns / 1ps

module DeMux(
    input [1:0] S,
    input En,
    output EnA,
    output EnB,
    output EnC,
    output EnD
    );
assign EnA = (S == 2'b00) ? 1'b0 : 1'b1;
assign EnB = (S == 2'b01) ? 1'b0 : 1'b1;
assign EnC = (S == 2'b10) ? 1'b0 : 1'b1;
assign EnD = (S == 2'b11) ? 1'b0 : 1'b1;

endmodule
