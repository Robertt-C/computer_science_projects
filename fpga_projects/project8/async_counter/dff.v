/*
module d_ff(
	clock,
	reset,
	d,
	Q
);

input clock, reset, d;
output reg Q;


always @ (posedge clock or posedge reset)
	begin

		if (reset == 1)
			Q <= 0;
		else 
			Q <= d;

	end

endmodule
*/