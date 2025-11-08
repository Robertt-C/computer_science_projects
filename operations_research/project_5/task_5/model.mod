var x1A binary;
var x1B binary;
var x1C binary;
var x1D binary;
var x1E binary;
var x2A binary;
var x2B binary;
var x2C binary;
var x2D binary;
var x2E binary;
var x3A binary;
var x3B binary;
var x3C binary;
var x3D binary;
var x3E binary;
var x4A binary;
var x4B binary;
var x4C binary;
var x4D binary;
var x4E binary;
var x5A binary;
var x5B binary;
var x5C binary;
var x5D binary;
var x5E binary;


minimize TotalDistance:
  230 * x1A + 
  200 * x1B + 
  210 * x1C + 
  240 * x1D + 
  220 * x1E + 
  190 * x2A + 
  210 * x2B + 
  200 * x2C + 
  200 * x2D + 
  190 * x2E + 
  200 * x3A + 
  180 * x3B + 
  240 * x3C + 
  220 * x3D + 
  210 * x3E + 
  220 * x4A + 
  180 * x4B + 
  210 * x4C + 
  230 * x4D + 
  220 * x4E + 
  210 * x5A + 
  190 * x5B + 
  200 * x5C + 
  220 * x5D + 
  210 * x5E;


subject to Warehouse1:
  x1A + 
  x1B + 
  x1C + 
  x1D + 
  x1E = 1;

subject to Warehouse2:
  x2A + 
  x2B + 
  x2C + 
  x2D + 
  x2E = 1;

subject to Warehouse3:
  x3A + 
  x3B + 
  x3C + 
  x3D + 
  x3E = 1;

subject to Warehouse4:
  x4A + 
  x4B + 
  x4C + 
  x4D + 
  x4E = 1;

subject to Warehouse5:
  x5A + 
  x5B + 
  x5C + 
  x5D + 
  x5E = 1;

subject to LocationA:
  x1A + 
  x2A + 
  x3A + 
  x4A + 
  x5A = 1;

subject to LocationB:
  x1B + 
  x2B + 
  x3B + 
  x4B + 
  x5B = 1;

subject to LocationC:
  x1C + 
  x2C + 
  x3C + 
  x4C + 
  x5C = 1;

subject to LocationD:
  x1D + 
  x2D + 
  x3D + 
  x4D + 
  x5D = 1;

subject to LocationE:
  x1E + 
  x2E + 
  x3E + 
  x4E + 
  x5E = 1;
