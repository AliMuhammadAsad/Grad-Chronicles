`timescale 1ns / 1ps

module testbench_v_counter();
reg clk; reg enable_v; wire[9:0] v_counter;

v_counter vc1(.clk(clk), .enable_v(enable_v), .v_counter(v_counter));
initial
begin
clk = 1'b0; 
enable_v = 1'b0;
end
always #5 clk = ~clk;
always #10 enable_v = ~enable_v;
endmodule