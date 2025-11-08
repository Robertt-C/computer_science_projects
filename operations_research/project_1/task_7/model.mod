var hours_D1 >= 0;
var hours_D2 >= 0;


maximize WeightedAverage:
  (3 * hours_D1 + 5 * hours_D2) / 8;


subject to TotalStudyTime:
  hours_D1 + 
  hours_D2 <= 30;

subject to MinPointsD1:
  5 * hours_D1 >= 50;

subject to MinPointsD2:
  4 * hours_D2 >= 50;