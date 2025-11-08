var x >= 0 integer;
var y >= 0 integer;


maximize Z:
  5 * x + 
  2 * y;


subject to Constraint1:
  3 * x + 
  1 * y <= 12;

subject to Constraint2:
  1 * x + 
  1 * y <= 5;
