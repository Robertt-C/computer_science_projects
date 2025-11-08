var x >= 0 integer;
var y >= 0 integer;


maximize Z:
  2 * x + 
  3 * y;


subject to Constraint1:
  1 * x + 
  2 * y <= 10;

subject to Constraint2:
  3 * x + 
  4 * y <= 25;
