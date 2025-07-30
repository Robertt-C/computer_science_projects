module sync_counter_3b(
	input clock, reset,
	output reg [2:0] Q
);




always @ (negedge clock)
	begin
		
		if (reset == 1)
			Q <= 3'b000;
		else
			Q <= Q + 3'b001;
	
	end

endmodule