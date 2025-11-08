var xAa >= 0;
var xAb >= 0;
var xAc >= 0;
var xAd >= 0;
var xAe >= 0;
var xBa >= 0;
var xBb >= 0;
var xBc >= 0;
var xBd >= 0;
var xBe >= 0;
var xCa >= 0;
var xCb >= 0;
var xCc >= 0;
var xCd >= 0;
var xCe >= 0;
var xDa >= 0;
var xDb >= 0;
var xDc >= 0;
var xDd >= 0;
var xDe >= 0;
var yA binary;
var yB binary;
var yC binary;
var yD binary;


minimize TotalCost:
  50 * yA + 
  32 * yB + 
  28 * yC + 
  36 * yD + 
  2 * xAa + 
  5 * xAb + 
  1 * xAc + 
  2 * xAd + 
  5 * xAe + 
  4 * xBa + 
  4 * xBb + 
  9 * xBc + 
  1 * xBd + 
  4 * xBe + 
  1 * xCa + 
  8 * xCb + 
  5 * xCc + 
  6 * xCd + 
  2 * xCe + 
  7 * xDa + 
  1 * xDb + 
  2 * xDc + 
  1 * xDd + 
  8 * xDe;


subject to CapacityA:
  xAa + 
  xAb + 
  xAc + 
  xAd + 
  xAe <= 35 * yA;

subject to CapacityB:
  xBa + 
  xBb + 
  xBc + 
  xBd + 
  xBe <= 28 * yB;

subject to CapacityC:
  xCa + 
  xCb + 
  xCc + 
  xCd + 
  xCe <= 22 * yC;

subject to CapacityD:
  xDa + 
  xDb + 
  xDc + 
  xDd + 
  xDe <= 28 * yD;

subject to DemandClientA:
  xAa + 
  xBa + 
  xCa + 
  xDa = 14;

subject to DemandClientB:
  xAb + 
  xBb + 
  xCb + 
  xDb = 12;

subject to DemandClientC:
  xAc + 
  xBc + 
  xCc + 
  xDc = 10;

subject to DemandClientD:
  xAd + 
  xBd + 
  xCd + 
  xDd = 12;

subject to DemandClientE:
  xAe + 
  xBe + 
  xCe + 
  xDe = 8;
