`timescale 1ns / 1ps

module v_counter(
    input clk,
    input enable_v,
    output reg [9:0] v_counter
    );
initial v_counter = 0;
always @ (posedge clk)
    begin
    if (v_counter < 524)
        begin
        if(enable_v == 1)
            begin 
                v_counter <= v_counter + 1;
            end
        else
            begin
                v_counter <= v_counter;
            end
        end
    else
        begin
            v_counter <= 0;
        end      
    end
endmodule
