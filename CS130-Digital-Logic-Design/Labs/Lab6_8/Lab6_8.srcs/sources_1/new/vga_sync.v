`timescale 1ns / 1ps

module vga_sync(
    input [9:0] h_count,
    input [9:0] v_count,
    output h_sync,
    output v_sync,
    output video_on, //active area
    output [9:0] x_loc,  //current pixel - x location
    output [9:0] y_loc  // current pixel - y location
    );
    //horizontal
    localparam HD = 640; //Horizontal Display
    localparam HF = 16; //Horizontal Right Border (Front Porch)
    localparam HB = 48; //Horizontal Left Border (Back Porch)
    localparam HR = 96; //Horizontal Retrace
    
    //vertical
    localparam VD = 480; //Vertical Display
    localparam VF = 10; //Vertical Bottom Border (Front Porch)
    localparam VB = 33; //Vertical Top Border (Back Porch)
    localparam VR = 2; //Vertical Retrace
    
//    reg h_sync; reg v_sync; reg video_on;
//    initial begin
    assign h_sync = (h_count < 656 || h_count > 751) ? 1 : 0;
    assign v_sync = (v_count < 490 || v_count > 491) ? 1 : 0;
    assign video_on = (h_count < HD && v_count < VD) ? 1 : 0;
//    end    
endmodule
