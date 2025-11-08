var x >= 0 integer;
var y >= 0 integer;


maximize Z:
  4 * x + 
  3 * y;


subject to Constraint1:
  4 * x + 
  9 * y <= 26;

subject to Constraint2:
  8 * x + 
  5 * y <= 17;
