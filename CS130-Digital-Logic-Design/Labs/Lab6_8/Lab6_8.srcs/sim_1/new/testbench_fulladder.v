module testbench_fulladder();
reg[2:0] mySW;
wire myLED1, myLED2;

fulladder test(mySW[2], mySW[1], mySW[0], myLED1, myLED2);

initial begin

#100 mySW = 3'b000;
#100 mySW = 3'b001;
#100 mySW = 3'b010;
#100 mySW = 3'b011;
#100 mySW = 3'b100;
#100 mySW = 3'b101;
#100 mySW = 3'b110;
#100 mySW = 3'b111;

end
endmodule