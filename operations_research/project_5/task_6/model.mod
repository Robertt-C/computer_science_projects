var xF1C1 >= 0;
var xF1C2 >= 0;
var xF1C3 >= 0;
var xF2C1 >= 0;
var xF2C2 >= 0;
var xF2C3 >= 0;
var xF3C1 >= 0;
var xF3C2 >= 0;
var xF3C3 >= 0;
var yF1C1 binary;
var yF1C2 binary;
var yF1C3 binary;
var yF2C1 binary;
var yF2C2 binary;
var yF2C3 binary;
var yF3C1 binary;
var yF3C2 binary;
var yF3C3 binary;


minimize TotalCost:
  10 * xF1C1 + 
  15 * xF1C2 + 
  12 * xF1C3 + 
  17 * xF2C1 + 
  14 * xF2C2 + 
  20 * xF2C3 + 
  15 * xF3C1 + 
  10 * xF3C2 + 
  11 * xF3C3 + 
  12000 * yF1C1 + 
  12000 * yF1C2 + 
  12000 * yF1C3 + 
  11000 * yF2C1 + 
  11000 * yF2C2 + 
  11000 * yF2C3 + 
  13000 * yF3C1 + 
  13000 * yF3C2 + 
  13000 * yF3C3;


subject to CapacityF1:
  xF1C1 + 
  xF1C2 + 
  xF1C3 <= 1800;

subject to CapacityF2:
  xF2C1 + 
  xF2C2 + 
  xF2C3 <= 1400;

subject to CapacityF3:
  xF3C1 + 
  xF3C2 + 
  xF3C3 <= 1300;

subject to DemandC1:
  xF1C1 + 
  xF2C1 + 
  xF3C1 = 1200;

subject to DemandC2:
  xF1C2 + 
  xF2C2 + 
  xF3C2 = 1700;

subject to DemandC3:
  xF1C3 + 
  xF2C3 + 
  xF3C3 = 1600;

subject to LinkF1C1:
  xF1C1 <= 10000 * yF1C1;

subject to LinkF1C2:
  xF1C2 <= 10000 * yF1C2;

subject to LinkF1C3:
  xF1C3 <= 10000 * yF1C3;

subject to LinkF2C1:
  xF2C1 <= 10000 * yF2C1;

subject to LinkF2C2:
  xF2C2 <= 10000 * yF2C2;

subject to LinkF2C3:
  xF2C3 <= 10000 * yF2C3;

subject to LinkF3C1:
  xF3C1 <= 10000 * yF3C1;

subject to LinkF3C2:
  xF3C2 <= 10000 * yF3C2;

subject to LinkF3C3:
  xF3C3 <= 10000 * yF3C3;
