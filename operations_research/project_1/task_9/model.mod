var shift_0 >= 0;
var shift_1 >= 0;
var shift_2 >= 0;
var shift_3 >= 0;
var shift_4 >= 0;
var shift_5 >= 0;
var shift_6 >= 0;
var shift_7 >= 0;
var shift_8 >= 0;
var shift_9 >= 0;
var shift_10 >= 0;
var shift_11 >= 0;
var shift_12 >= 0;
var shift_13 >= 0;
var shift_14 >= 0;
var shift_15 >= 0;
var shift_16 >= 0;
var shift_17 >= 0;
var shift_18 >= 0;
var shift_19 >= 0;
var shift_20 >= 0;
var shift_21 >= 0;
var shift_22 >= 0;
var shift_23 >= 0;


minimize TotalEmployees:
  shift_0 +
  shift_1 +
  shift_2 +
  shift_3 +
  shift_4 +
  shift_5 +
  shift_6 +
  shift_7 +
  shift_8 +
  shift_9 +
  shift_10 +
  shift_11 +
  shift_12 +
  shift_13 +
  shift_14 +
  shift_15 +
  shift_16 +
  shift_17 +
  shift_18 +
  shift_19 +
  shift_20 +
  shift_21 +
  shift_22 +
  shift_23;


subject to Period0206:
  shift_22 +
  shift_23 +
  shift_0 +
  shift_1 +
  shift_2 +
  shift_3 +
  shift_4 +
  shift_5 >= 4;

subject to Period0610:
  shift_2 +
  shift_3 +
  shift_4 +
  shift_5 +
  shift_6 +
  shift_7 +
  shift_8 +
  shift_9 >= 8;

subject to Period1014:
  shift_6 +
  shift_7 +
  shift_8 +
  shift_9 +
  shift_10 +
  shift_11 +
  shift_12 +
  shift_13 >= 10;

subject to Period1418:
  shift_10 +
  shift_11 +
  shift_12 +
  shift_13 +
  shift_14 +
  shift_15 +
  shift_16 +
  shift_17 >= 7;

subject to Period1822:
  shift_14 +
  shift_15 +
  shift_16 +
  shift_17 +
  shift_18 +
  shift_19 +
  shift_20 +
  shift_21 >= 12;

subject to Period2202:
  shift_18 +
  shift_19 +
  shift_20 +
  shift_21 +
  shift_22 +
  shift_23 +
  shift_0 +
  shift_1 >= 4;