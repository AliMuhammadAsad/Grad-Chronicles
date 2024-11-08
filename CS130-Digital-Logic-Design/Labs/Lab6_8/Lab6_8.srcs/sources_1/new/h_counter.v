`timescale 1ns / 1ps

module h_counter(
    input clk,
    output [9:0] h_count,
    output trig_v
    );
reg[9:0] h_count;
reg trig_v;
initial h_count = 0;
always @ (posedge clk)
    begin
        if (h_count < 799)
            begin
                h_count <= h_count + 1; trig_v <= 0;
            end
        else
            begin
                trig_v <= 1;
                h_count <= 0;
            end
    end
endmodule
