`timescale 1ns / 1ps

module complement_2s(
    input [2:0] B,
    input O,
    output [2:0] C
    );
assign C[2] = ~O&B[2] || B[2]&~B[1]&~B[0] || O&~B[2]&B[0] || O&~B[2]&B[1];
assign C[1] = ~O&B[1] || B[1]&~B[0] || O&~B[1]&B[0] ;
assign C[0] = B[0] ;
endmodule
