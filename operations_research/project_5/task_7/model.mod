var hireMonth1 >= 0 integer;
var hireMonth2 >= 0 integer;
var hireMonth3 >= 0 integer;
var hireMonth4 >= 0 integer;
var hireMonth5 >= 0 integer;
var hireMonth6 >= 0 integer;
var hireMonth7 >= 0 integer;
var hireMonth8 >= 0 integer;
var hireMonth9 >= 0 integer;
var hireMonth10 >= 0 integer;
var hireMonth11 >= 0 integer;
var hireMonth12 >= 0 integer;


minimize TotalCost:
  3 * 10 * hireMonth1 + 
  3 * 10 * hireMonth2 + 
  3 * 12 * hireMonth3 + 
  3 * 15 * hireMonth4 + 
  3 * 15 * hireMonth5 + 
  3 * 10 * hireMonth6 + 
  3 * 12 * hireMonth7 + 
  3 * 15 * hireMonth8 + 
  3 * 14 * hireMonth9 + 
  3 * 15 * hireMonth10 + 
  3 * 15 * hireMonth11 + 
  3 * 14 * hireMonth12;


subject to NeedMonth1:
  hireMonth1 + 
  hireMonth12 + 
  hireMonth11 >= 200;

subject to NeedMonth2:
  hireMonth2 + 
  hireMonth1 + 
  hireMonth12 >= 250;

subject to NeedMonth3:
  hireMonth3 + 
  hireMonth2 + 
  hireMonth1 >= 180;

subject to NeedMonth4:
  hireMonth4 + 
  hireMonth3 + 
  hireMonth2 >= 170;

subject to NeedMonth5:
  hireMonth5 + 
  hireMonth4 + 
  hireMonth3 >= 190;

subject to NeedMonth6:
  hireMonth6 + 
  hireMonth5 + 
  hireMonth4 >= 130;

subject to NeedMonth7:
  hireMonth7 + 
  hireMonth6 + 
  hireMonth5 >= 190;

subject to NeedMonth8:
  hireMonth8 + 
  hireMonth7 + 
  hireMonth6 >= 140;

subject to NeedMonth9:
  hireMonth9 + 
  hireMonth8 + 
  hireMonth7 >= 175;

subject to NeedMonth10:
  hireMonth10 + 
  hireMonth9 + 
  hireMonth8 >= 100;

subject to NeedMonth11:
  hireMonth11 + 
  hireMonth10 + 
  hireMonth9 >= 150;

subject to NeedMonth12:
  hireMonth12 + 
  hireMonth11 + 
  hireMonth10 >= 160;
