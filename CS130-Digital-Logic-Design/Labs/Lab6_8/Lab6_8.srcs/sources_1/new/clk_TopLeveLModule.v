`timescale 1ns / 1ps
module clk_TopLeveLModule(
    input clk,
    output [9:0] h_count,
    output [9:0] v_count
    );
    wire clk_div_out; 
    wire trig_v;
    clk_div cd1(clk, clk_div_out);
    h_counter(clk_div_out, h_count, trig_v);
    v_counter(clk, trig_v, v_count);
endmodule
