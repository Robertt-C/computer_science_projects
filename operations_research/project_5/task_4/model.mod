var item1 binary;
var item2 binary;
var item3 binary;
var item4 binary;
var item5 binary;


maximize Revenue:
  (0.50 * 1000 + 700) * item1 + 
  (0.50 * 1100 + 800) * item2 + 
  (0.50 * 700 + 1100) * item3 + 
  (0.50 * 800 + 1000) * item4 + 
  (0.50 * 500 + 700) * item5;


subject to MaxWeight:
  1000 * item1 + 
  1100 * item2 + 
  700 * item3 + 
  800 * item4 + 
  500 * item5 <= 2000;

subject to MaxVolume:
  7 * item1 + 
  10 * item2 + 
  10 * item3 + 
  8 * item4 + 
  5 * item5 <= 20;
