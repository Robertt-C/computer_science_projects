var A_1 >= 0;
var A_2 >= 0;
var A_3 >= 0;
var A_4 >= 0;
var A_5 >= 0;
var B_1 >= 0;
var B_2 >= 0;
var B_3 >= 0;
var B_4 >= 0;
var B_5 >= 0;
var C_2 >= 0;
var D_5 >= 0;


maximize Money:
  1.4 * A_1 +
  1.4 * A_2 +
  1.4 * A_3 +
  1.4 * A_4 +
  A_5 +
  1.7 * B_1 +
  1.7 * B_2 +
  1.7 * B_3 +
  B_4 +
  B_5 +
  2.0 * C_2 +
  1.3 * D_5;


subject to Year1Constraint:
  A_1 +
  B_1 <= 10000;

subject to Year2Constraint:
  A_2 +
  B_2 +
  C_2 <= 10000 - A_1 - B_1;

subject to Year3Constraint:
  A_3 +
  B_3 <= 10000 - A_1 - B_1 - A_2 - B_2 - C_2 + 1.4 * A_1;

subject to Year4Constraint:
  A_4 +
  B_4 <= 10000 - A_1 - B_1 - A_2 - B_2 - C_2 + 1.4 * A_1 - A_3 - B_3 + 1.4 * A_2 + 1.7 * B_1;

subject to Year5Constraint:
  A_5 +
  B_5 +
  D_5 <= 10000 - A_1 - B_1 - A_2 - B_2 - C_2 + 1.4 * A_1 - A_3 - B_3 + 1.4 * A_2 + 1.7 * B_1 - A_4 - B_4 + 1.4 * A_3 + 1.7 * B_2;