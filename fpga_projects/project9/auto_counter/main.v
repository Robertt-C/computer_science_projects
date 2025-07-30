module main(
	input wire fpga_clock, reset,
	output wire filtered_clock,
	output wire [3:0] Q,
	output wire a, b, c, d, e, f, g
);




	frequency_divider frequency_divider_1hz(.clock(fpga_clock), .filtered_clock(filtered_clock));
	counter_4b counter(filtered_clock, reset, Q);
	decoder_o_nine decoder(Q[3], Q[2], Q[1], Q[0], a, b, c, d, e, f, g);

endmodule