var x1 binary;
var x2 binary;
var x3 binary;
var x4 binary;
var x5 binary;
var x6 binary;
var x7 binary;


maximize Z:
  10 * x1 + 
  15 * x2 + 
  36 * x3 + 
  20 * x4 + 
  15 * x5 + 
  18 * x6 + 
  20 * x7;


subject to KnapsackCapacity:
  10 * x1 + 
  17 * x2 + 
  49 * x3 + 
  30 * x4 + 
  11 * x5 + 
  21 * x6 + 
  31 * x7 <= 100;
