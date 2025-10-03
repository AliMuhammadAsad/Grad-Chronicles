`timescale 1ns / 1ps

module my_or(
    input SW1,
    input SW2,
    output LED
    );
or u1(LED, SW1, SW2);
endmodule
