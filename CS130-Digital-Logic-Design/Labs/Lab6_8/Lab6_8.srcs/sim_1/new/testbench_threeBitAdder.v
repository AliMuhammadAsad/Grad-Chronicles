module testbench_threeBitAdder();
reg[2:0] aA;
reg[2:0] bB;

wire [2:0] yY; wire cCout;
threeBitAdder test(aA, bB, yY, cCout);

initial begin
#100 aA =3'b 110 ; bB = 3'b 010; //8
#100 aA =3'b 101 ; bB = 3'b 011; //8
#100 aA =3'b 100 ; bB = 3'b 110; //10
#100 aA =3'b 111 ; bB = 3'b 101; //12
#100 aA =3'b 010 ; bB = 3'b 100; //6
#100 aA =3'b 011 ; bB = 3'b 001; //4

//#100 aA =3'b 111 ; bB = 3'b 001; //8
//#100 aA =3'b 110 ; bB = 3'b 100; //10
//#100 aA =3'b 110 ; bB = 3'b 110; //12
//#100 aA =3'b 101 ; bB = 3'b 001; //6
//#100 aA =3'b 101 ; bB = 3'b 000; //4

end
endmodule