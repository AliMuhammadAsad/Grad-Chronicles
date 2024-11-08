`timescale 1ns / 1ps

module and_gate(
    input sw1,
    input sw2,
    output LED
    );
and u1(LED, sw1, sw2);

endmodule
