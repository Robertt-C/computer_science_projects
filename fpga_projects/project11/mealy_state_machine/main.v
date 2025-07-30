module main(
	input wire clock, reset,
	input wire [1:0] select,
	
	output wire [3:0] out,
	output wire filtered_clock,
	output wire a, b, c, d, e, f, g
);




frequency_divider divider(clock, filtered_clock);
mealy_state_machine state_machine(filtered_clock, reset, select, out);
decoder_o_nine decoder(out[3], out[2], out[1], out[0], a, b, c, d, e, f, g);


endmodule