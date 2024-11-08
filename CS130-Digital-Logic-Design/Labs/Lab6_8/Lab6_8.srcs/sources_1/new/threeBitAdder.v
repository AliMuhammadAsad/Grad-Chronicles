`timescale 1ns / 1ps

module threeBitAdder(
    input [2:0] A,
    input [2:0] B,
    output [2:0] Y,
    output Cout
    );
wire res1, res2;

fulladder t1(A[0], B[0], 0, Y[0], res1);
fulladder t2(A[1], B[1], res1, Y[1], res2);
fulladder t3(A[2], B[2], res2, Y[2], Cout);
    
endmodule
