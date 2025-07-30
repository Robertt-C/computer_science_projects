module counter_4b(
	input clock, reset,
	output reg [3:0] Q
);


always @ (negedge clock or posedge reset)
	begin
		
		if (reset == 1)
			
			begin
				Q <= 4'b0000;
			end
			
		else if (Q == 4'b1001)
			
			begin
				Q <= 4'b0000;
			
			end
		else
			Q <= Q + 4'b0001;
	
	end
	
endmodule