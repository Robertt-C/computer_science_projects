var xA1 >= 0;
var xA2 >= 0;
var xA3 >= 0;
var xA4 >= 0;
var xA5 >= 0;
var xB1 >= 0;
var xB2 >= 0;
var xB3 >= 0;
var xB4 >= 0;
var xB5 >= 0;
var xC1 >= 0;
var xC2 >= 0;
var xC3 >= 0;
var xC4 >= 0;
var xC5 >= 0;


minimize Cost:
  4 * xA1 + 
  1 * xA2 + 
  2 * xA3 + 
  6 * xA4 + 
  9 * xA5 + 
  6 * xB1 + 
  4 * xB2 + 
  3 * xB3 + 
  5 * xB4 + 
  7 * xB5 + 
  5 * xC1 + 
  2 * xC2 + 
  6 * xC3 + 
  4 * xC4 + 
  8 * xC5;


subject to FactoryA:
  xA1 + 
  xA2 + 
  xA3 + 
  xA4 + 
  xA5 <= 160;

subject to FactoryB:
  xB1 + 
  xB2 + 
  xB3 + 
  xB4 + 
  xB5 <= 160;

subject to FactoryC:
  xC1 + 
  xC2 + 
  xC3 + 
  xC4 + 
  xC5 <= 160;

subject to Warehouse1:
  xA1 + 
  xB1 + 
  xC1 = 40;

subject to Warehouse2:
  xA2 + 
  xB2 + 
  xC2 = 80;

subject to Warehouse3:
  xA3 + 
  xB3 + 
  xC3 = 70;

subject to Warehouse4:
  xA4 + 
  xB4 + 
  xC4 = 90;

subject to Warehouse5:
  xA5 + 
  xB5 + 
  xC5 = 60;
