`timescale 1ns / 1ps

module TopLevelModule_vga(
    input clk,
    output h_sync,
    output v_sync,
    output [3:0] red,
    output [3:0] green,
    output [3:0] blue
    );
    wire clk_d; wire trig_v; wire video_on;
    wire [9:0] h_count; wire [9:0] v_count; wire [9:0] x_loc; wire [9:0] y_loc;
    
    clk_div clkd(clk, clk_d);
    h_counter hc(clk_d, h_count, trig_v);
    v_counter vc(clk_d, trig_v, v_count);
    vga_sync vgas(h_count, v_count, h_sync, v_sync, video_on, x_loc, y_loc);
    pixel_gen pg(clk_d, x_loc, y_loc, video_on, red, blue, green);
    
endmodule
