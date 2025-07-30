module frequency_divider(
	input clock,
	output reg filtered_clock,
	output reg [25:0] out
);




always @ (posedge clock)
	if (out == 26'd50000000)
		
		begin
			out <= 26'd0;
			filtered_clock <= 1;
		end
		
	else
		
		begin
			out <= out + 26'd1;
			filtered_clock <= 0;
		end

endmodule