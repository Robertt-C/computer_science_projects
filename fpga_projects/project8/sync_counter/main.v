module main (
	input wire clock, reset,
	output wire [2:0] Q,
	output wire a, b, c, d, e, f, g
);




	sync_counter_3b counter(clock, reset, Q);
	decoder_o_nine decoder(1'b0, Q[2], Q[1], Q[0], a, b, c, d, e, f, g);


endmodule