`timescale 1ns / 1ps

module testbench_my_or();

reg [1:0] mySW;
wire myLED;

my_or test(mySW[1], mySW[0], myLED);

initial begin

#100 mySW = 2'b00;
#100 mySW = 2'b01;
#100 mySW = 2'b10;
#100 mySW = 2'b11;

end

endmodule