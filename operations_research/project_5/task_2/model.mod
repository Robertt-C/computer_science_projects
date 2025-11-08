var fuelA >= 0;
var fuelB >= 0;


maximize Profit:
  (0.70 - 0.30 * 0.30 - 0.30 * 0.60 - 0.40 * 0.50) * fuelA + 
  (0.90 - 0.50 * 0.60 - 0.50 * 0.50) * fuelB;


subject to GasolineType1:
  0.30 * fuelA <= 100000;

subject to GasolineType2:
  0.30 * fuelA + 
  0.50 * fuelB <= 250000;

subject to GasolineType3:
  0.40 * fuelA + 
  0.50 * fuelB <= 280000;
