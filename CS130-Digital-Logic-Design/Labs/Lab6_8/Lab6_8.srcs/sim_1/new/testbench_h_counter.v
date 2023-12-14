`timescale 1ns / 1ps

module testbench_h_counter();
reg clk; wire [9:0] h_count; wire trig_v;

h_counter h_c1(.clk(clk), .h_count(h_count), .trig_v(trig_v));
initial
clk = 1'b0;
always
    #5 clk = ~clk;
endmodule