`timescale 1ns / 1ps

module clk_div_testbench();
    reg clk;
    wire clk_d;
    clk_div cd1(.clk(clk), .clk_d(clk_d));
    initial
    begin 
        clk = 1'b0; 
    end
    
    always
        #5 clk = ~clk;
endmodule