`timescale 1ns / 1ps

module pixel_gen(
    input clk_d, //pixel clock
    input [9:0] pixel_x,
    input [9:0] pixel_y,
    input video_on,
    output reg [3:0] red = 0,
    output reg [3:0] blue = 0,
    output reg [3:0] green = 0
    );
    
    always @(posedge clk_d) begin
        if ((pixel_x == 0) || (pixel_x == 639) || (pixel_y == 0) || (pixel_y == 479)) begin
            red <= 4'hF;
            green <= 4'hF;
            blue <= 4'hF;
            end
        else begin
            red <= video_on ? (pixel_y > 240 ? 4'hF : 4'h0) : (4'h0);
            green <= video_on ? (pixel_y > 240 ? 4'hF : 4'h0) : (4'h0);
            blue <= 4'h0;
            end
        end
    
endmodule
