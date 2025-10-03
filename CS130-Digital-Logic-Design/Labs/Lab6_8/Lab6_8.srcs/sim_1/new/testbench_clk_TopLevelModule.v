`timescale 1ns / 1ps

module testbench_clk_TopLevelModule();
reg clk;
wire [9:0] h_count;
wire [9:0] v_count;

clk_TopLevelModule clkTLM(clk, h_count, v_count);
initial
clk = 1'b0;
always
#1 clk = ~clk;

endmodule