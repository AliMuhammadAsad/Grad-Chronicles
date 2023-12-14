`timescale 1ns / 1ps

module fulladder(
    input A,
    input B,
    input C,
    output O1,
    output O2
    );
wire res1, res2, res3;
my_xor xor1(A, B, res1);
my_xor xor2(res1, C, O1);
and_gate and1(A, B, res2);
and_gate and2(res1, C, res3);
my_or or1(res3, res2, O2);
endmodule
