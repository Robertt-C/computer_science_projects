var antenna1 binary;
var antenna2 binary;
var antenna3 binary;
var antenna4 binary;
var antenna5 binary;
var antenna6 binary;
var community1 binary;
var community2 binary;
var community3 binary;
var community4 binary;
var community5 binary;
var community6 binary;
var community7 binary;
var community8 binary;
var community9 binary;


maximize TotalPopulation:
  5 * community1 + 
  8 * community2 + 
  6 * community3 + 
  7 * community4 + 
  9 * community5 + 
  13 * community6 + 
  11 * community7 + 
  7 * community8 + 
  4 * community9;


subject to MaxBudget:
  2.2 * antenna1 + 
  2.3 * antenna2 + 
  2.5 * antenna3 + 
  4.1 * antenna4 + 
  4.8 * antenna5 + 
  5.1 * antenna6 <= 7.4;

subject to MaxAntennas:
  antenna1 + 
  antenna2 + 
  antenna3 + 
  antenna4 + 
  antenna5 + 
  antenna6 <= 6;

subject to Coverage1:
  community1 <= antenna1 + 
  antenna6;

subject to Coverage2:
  community2 <= antenna1 + 
  antenna2;

subject to Coverage3:
  community3 <= antenna2 + 
  antenna5 + 
  antenna6;

subject to Coverage4:
  community4 <= antenna1 + 
  antenna4 + 
  antenna6;

subject to Coverage5:
  community5 <= antenna4 + 
  antenna5;

subject to Coverage6:
  community6 <= antenna2 + 
  antenna3 + 
  antenna4 + 
  antenna5;

subject to Coverage7:
  community7 <= antenna4 + 
  antenna6;

subject to Coverage8:
  community8 <= antenna3 + 
  antenna5;

subject to Coverage9:
  community9 <= antenna5 + 
  antenna6;
