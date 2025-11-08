var product_1 >= 0;
var product_2 >= 0;
var product_3 >= 0;


maximize Profit:
  product_1 * 30 +
  product_2 * 12 +
  product_3 * 15;


subject to MachineAMaximumTime:
  9 * product_1 +
  3 * product_2 +
  5 * product_3 <= 500;

subject to MachineBMaximumTime:
  5 * product_1 +
  4 * product_2 +
  0 * product_3 <= 350;

subject to MachineCMaximumTime:
  3 * product_1 +
  0 * product_2 +
  2 * product_3 <= 150;

subject to Product3SalesLimit:
  product_3 <= 20;