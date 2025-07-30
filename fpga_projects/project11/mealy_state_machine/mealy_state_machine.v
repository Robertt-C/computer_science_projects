module mealy_state_machine(
	input clock, reset,
	input [1:0] select,
	output reg [3:0] out
);

reg [3:0] actualState, nextState;
parameter [3:0] A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, displayOff = 9;




always @ (select or actualState)
	begin
	
	case (actualState)
		
		A:
			case (select)
				
				2'b00:
					begin
					nextState = A;
					out = 7;
					end
				2'b01:
					begin
					
					if (reset == 1)
					    begin
					    out = 7;
					    end
					else
					    begin
					    out = 6;
					    end
					
					nextState = I;
					
					end
					2'b10:
					begin
					
					if (reset == 1)
					    begin
					    out = 7;
					    end
					else
					    begin
					    out = 5;
					    end
					    
					nextState = B;
					
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
					
			endcase
					
		B:
			case (select)
				
				2'b00:
					begin
					nextState = B;
					out = 5;
					end
				2'b01:
					begin
					nextState = A;
					out = 7;
					end
				2'b10:
					begin
					nextState = C;
					out = 1;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
			
			endcase
			
		C:
			case (select)
				
				2'b00:
					begin
					nextState = C;
					out = 1;
					end
				2'b01:
					begin
					nextState = B;
					out = 5;
					end
				2'b10:
					begin
					nextState = D;
					out = 4;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
					
			endcase
			
		D:
			case (select)
				
				2'b00:
					begin
					nextState = D;
					out = 4;
					end
				2'b01:
					begin
					nextState = C;
					out = 1;
					end
				2'b10:
					begin
					nextState = E;
					out = 2;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
			endcase
			
		E:
			case (select)
				
				2'b00:
					begin
					nextState = E;
					out = 2;
					end
				2'b01:
					begin
					nextState = D;
					out = 4;
					end
				2'b10:
					begin
					nextState = F;
					out = 3;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
					
			endcase
			
		F:
			case (select)
				
				2'b00:
					begin
					nextState = F;
					out = 3;
					end
				2'b01:
					begin
					nextState = E;
					out = 2;
					end
				2'b10:
					begin
					nextState = G;
					out = 0;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
					
			endcase
			
		G:
			case (select)
				
				2'b00:
					begin
					nextState = G;
					out = 0;
					end
				2'b01:
					begin
					nextState = F;
					out = 3;
					end
				2'b10:
					begin
					nextState = H;
					out = 2;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
					
			endcase		
			
		H:
			case (select)
				
				2'b00:
					begin
					nextState = H;
					out = 2;
					end
				2'b01:
					begin
					nextState = G;
					out = 0;
					end
				2'b10:
					begin
					nextState = I;
					out = 6;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
					
			endcase
			
		I:
			case (select)
				
				2'b00:
					begin
					nextState = I;
					out = 6;
					end
				2'b01:
					begin
					nextState = H;
					out = 2;
					end
				2'b10:
					begin
					nextState = A;
					out = 7;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
			endcase
		
		displayOff:
			case (select)
				2'b00:
					begin
					nextState = displayOff;
					out = 15;
					end
				2'b01:
					begin
					nextState = A;
					out = 7;
					end
				2'b10:
					begin
					nextState = A;
					out = 7;
					end
				2'b11:
					begin
					nextState = displayOff;
					out = 15;
					end
			endcase
		
	endcase
		
	end


always @ (posedge clock or posedge reset)
	begin
	
	if (reset == 1)
		actualState <= A;
	else
		actualState <= nextState;
	
	end


endmodule