var x1 >= 0 integer;
var x2 >= 0 integer;
var x3 >= 0 integer;


maximize Z:
  6 * x1 + 
  9 * x2 + 
  7 * x3;


subject to Constraint:
  3 * x1 + 
  5 * x2 + 
  4 * x3 <= 14;
