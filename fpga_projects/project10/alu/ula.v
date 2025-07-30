module ula(
	input [3:0] A, B,
	input [2:0] select,
	output reg [3:0] out
);




always @ (*)

	case (select)
		
		3'b000: out = A & B;
		
		3'b001: out = A | B;
		
		3'b010: out = A + B;

		3'b011: out = A - B;
		
		3'b100: out = A * B;
		
		3'b101: out = A / B;

endcase


endmodule