var product_1 >= 0;
var product_2 >= 0;
var product_3 >= 0;
var product_4 >= 0;


maximize Profit:
  product_1 * (65 - (2 * 10 + 3 * 15)) +
  product_2 * (70 - (3 * 10 + 2 * 15)) +
  product_3 * (55 - (4 * 10 + 1 * 15)) +
  product_4 * (45 - (2 * 10 + 2 * 15));


subject to Machine1MaximumTime:
  2 * product_1 +
  3 * product_2 +
  4 * product_3 +
  2 * product_4 <= 500;

subject to Machine2MaximumTime:
  3 * product_1 +
  2 * product_2 +
  1 * product_3 +
  2 * product_4 <= 380;