module main(
	input wire [2:0] select,
	input wire [3:0] A, B,
	output wire [3:0] Q,
	output wire a, b, c, d, e, f, g
);




ula ula1(A, B, select, Q);
decoder_o_nine decoder(Q[3], Q[2], Q[1], Q[0], a, b, c, d, e, f, g);


endmodule