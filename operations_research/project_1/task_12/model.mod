var x_11 >= 0;
var x_12 >= 0;
var x_13 >= 0;
var x_21 >= 0;
var x_22 >= 0;
var x_23 >= 0;
var x_31 >= 0;
var x_32 >= 0;
var x_33 >= 0;
var x_41 >= 0;
var x_42 >= 0;
var x_43 >= 0;


minimize Cost:
  0.20 * (x_11 + x_12 + x_13) +
  0.12 * (x_21 + x_22 + x_23) +
  0.24 * (x_31 + x_32 + x_33) +
  0.12 * (x_41 + x_42 + x_43);


subject to CattleTotalWeight:
  x_11 +
  x_21 +
  x_31 +
  x_41 = 10000;

subject to SheepTotalWeight:
  x_12 +
  x_22 +
  x_32 +
  x_42 = 6000;

subject to ChickenTotalWeight:
  x_13 +
  x_23 +
  x_33 +
  x_43 = 8000;

subject to CornAvailability:
  x_11 +
  x_12 +
  x_13 <= 6000;

subject to LimestoneAvailability:
  x_21 +
  x_22 +
  x_23 <= 10000;

subject to SoyAvailability:
  x_31 +
  x_32 +
  x_33 <= 4000;

subject to FishFlourAvailability:
  x_41 +
  x_42 +
  x_43 <= 5000;

subject to CattleVitaminMin:
  8 * x_11 +
  6 * x_21 +
  10 * x_31 +
  4 * x_41 >= 6 * 10000;

subject to CattleProteinMin:
  10 * x_11 +
  5 * x_21 +
  12 * x_31 +
  8 * x_41 >= 6 * 10000;

subject to CattleCalciumMin:
  6 * x_11 +
  10 * x_21 +
  6 * x_31 +
  6 * x_41 >= 7 * 10000;

subject to CattleFatMin:
  8 * x_11 +
  6 * x_21 +
  6 * x_31 +
  9 * x_41 >= 4 * 10000;

subject to CattleFatMax:
  8 * x_11 +
  6 * x_21 +
  6 * x_31 +
  9 * x_41 <= 8 * 10000;

subject to SheepVitaminMin:
  8 * x_12 +
  6 * x_22 +
  10 * x_32 +
  4 * x_42 >= 6 * 6000;

subject to SheepProteinMin:
  10 * x_12 +
  5 * x_22 +
  12 * x_32 +
  8 * x_42 >= 6 * 6000;

subject to SheepCalciumMin:
  6 * x_12 +
  10 * x_22 +
  6 * x_32 +
  6 * x_42 >= 6 * 6000;

subject to SheepFatMin:
  8 * x_12 +
  6 * x_22 +
  6 * x_32 +
  9 * x_42 >= 4 * 6000;

subject to SheepFatMax:
  8 * x_12 +
  6 * x_22 +
  6 * x_32 +
  9 * x_42 <= 8 * 6000;

subject to ChickenVitaminMin:
  8 * x_13 +
  6 * x_23 +
  10 * x_33 +
  4 * x_43 >= 4 * 8000;

subject to ChickenVitaminMax:
  8 * x_13 +
  6 * x_23 +
  10 * x_33 +
  4 * x_43 <= 6 * 8000;

subject to ChickenProteinMin:
  10 * x_13 +
  5 * x_23 +
  12 * x_33 +
  8 * x_43 >= 6 * 8000;

subject to ChickenCalciumMin:
  6 * x_13 +
  10 * x_23 +
  6 * x_33 +
  6 * x_43 >= 6 * 8000;

subject to ChickenFatMin:
  8 * x_13 +
  6 * x_23 +
  6 * x_33 +
  9 * x_43 >= 4 * 8000;

subject to ChickenFatMax:
  8 * x_13 +
  6 * x_23 +
  6 * x_33 +
  9 * x_43 <= 8 * 8000;