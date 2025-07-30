module main(
	input wire fpga_clock, clock, reset,
	output wire clock_output,
	output wire [3:0] Q,
	output wire a, b, c, d, e, f, g
);


debouncer debounce(.fpga_clock(fpga_clock), .clock(clock), .clock_output(clock_output));
counter_4b counter(clock_output, reset, Q);
decoder_o_nine decoder(Q[3], Q[2], Q[1], Q[0], a, b, c, d, e, f, g);


endmodule