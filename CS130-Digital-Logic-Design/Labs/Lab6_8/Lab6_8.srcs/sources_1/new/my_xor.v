`timescale 1ns / 1ps

module my_xor(
    input A,
    input B,
    output C
    );
wire C0, C1;
and_gate and1(~A, B, C0);
and_gate and2(A, ~B, C1);
my_or res(C0, C1, C);

endmodule
