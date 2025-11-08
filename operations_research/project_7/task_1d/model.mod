var x >= 0 integer;
var y >= 0 integer;


maximize Z:
  1 * x + 
  1 * y;


subject to Constraint1:
  2 * x + 
  2 * y <= 3;

subject to Constraint2:
  7 * x + 
  3 * y <= 22;
