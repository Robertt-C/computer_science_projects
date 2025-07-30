module debouncer(
	input fpga_clock, clock,
	output reg clock_output,
	output reg [2:0] Q
);

always @ (negedge fpga_clock)
	begin
	
		Q[0] <= clock;
		Q[1] <= Q[0];
		Q[2] <= Q[1];
		
		clock_output <= Q[2] & Q[1] & Q[0];
		
	end

endmodule