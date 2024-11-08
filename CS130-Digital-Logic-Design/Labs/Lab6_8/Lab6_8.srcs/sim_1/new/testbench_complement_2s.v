`timescale 1ns / 1ps

module testbench_complement_2s();

reg[2:0] bB;
reg oO;
wire [2:0] cC;

complement_2s test(bB, oO, cC);

initial begin

#100 bB = 3'b000; oO = 0;
#100 bB = 3'b001; oO = 0;
#100 bB = 3'b010; oO = 0;
#100 bB = 3'b011; oO = 0;
#100 bB = 3'b101; oO = 0;
#100 bB = 3'b111; oO = 0;
#100 bB = 3'b000; oO = 1;
#100 bB = 3'b001; oO = 1;
#100 bB = 3'b010; oO = 1;
#100 bB = 3'b011; oO = 1;
#100 bB = 3'b101; oO = 1;
#100 bB = 3'b111; oO = 1;

end
endmodule