var packagesA >= 0;
var packagesB >= 0;


maximize Profit:
  5000 * packagesA + 
  10000 * packagesB;


subject to TinturariaHours:
  2 * packagesA + 
  1.5 * packagesB <= 15;

subject to FiacaoHours:
  1 * packagesA + 
  3 * packagesB <= 13;
