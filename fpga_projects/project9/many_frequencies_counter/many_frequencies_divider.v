module many_frequencies_divider(
	input clock, select1, select2,
	output reg filtered_clock,
	output reg [28:0] out
);




always @ (posedge clock)
	begin
	
		
	case({select1, select2})
	
	2'b00:
	if (out == 29'd25000000)		
		begin
			out <= 29'd0;
			filtered_clock <= 1;
		end
	else
		begin
			out <= out + 29'd1;
			filtered_clock <= 0;
		end
			
		
	2'b01:
	if (out == 29'd50000000)
		begin
			out <= 29'd0;
			filtered_clock <= 1;
		end
	else
		begin
			out <= out + 29'd1;
			filtered_clock <= 0;
		end
		
		
	2'b10:
	if (out == 29'd100000000)
		begin
			out <= 29'd0;
			filtered_clock <= 1;
		end
	else
		begin
			out <= out + 29'd1;
			filtered_clock <= 0;
		end
		

	2'b11:
	if (out == 29'd300000000)
		begin
			out <= 29'd0;
			filtered_clock <= 1;
		end
	else
		begin
			out <= out + 29'd1;
			filtered_clock <= 0;
		end
		
	endcase
	end

endmodule