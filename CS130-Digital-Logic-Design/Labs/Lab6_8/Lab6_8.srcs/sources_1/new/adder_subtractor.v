`timescale 1ns / 1ps

module adder_subtractor(
    input [2:0] A,
    input [2:0] B,
    input O,
    output [6:0] S,
    output X
    );
wire[2:0] C;
wire[2:0] Sum;
wire[2:0] D;
wire[3:0] sX; 
wire carry, E, Y;
complement_2s c1(B, O, C);
threeBitAdder tba(A, C, Sum, carry);
my_or or1(~O, carry, X);
and_gate and1(~O, carry, E);
assign sX = {E, D};
complement_2s c2(Sum, ~X, D);
segment_decoder s1(sX, S);

//complement_2s c1(B, O, C);
//threeBitAdder tba(A, C, Sum, carry);
//assign X = ~O || carry;
//assign E = ~O & carry;
//assign sX = {E, D};
//complement_2s c2(Sum, ~X, D);
//segment_decoder s1(sX, S);

endmodule
