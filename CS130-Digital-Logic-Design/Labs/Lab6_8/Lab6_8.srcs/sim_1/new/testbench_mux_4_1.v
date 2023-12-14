`timescale 1ns / 1ps

module testbench_mux_4_1();
reg[1:0] S;
reg[3:0] A;
reg[3:0] B;
reg[3:0] C;
reg[3:0] D;
wire[3:0] Y;

mux_4_1 test_mux_4(S, A, B, C, D, Y);

initial begin
A [3:0] = 4'b0111;
B [3:0] = 4'b0001;
C [3:0] = 4'b1001;
D [3:0] = 4'b0000;

#100 S = 2'b00;
#100 S = 2'b01;
#100 S = 2'b10;
#100 S = 2'b11;

end
endmodule