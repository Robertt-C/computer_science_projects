var institutional >= 0;
var direct_p1 >= 0;
var direct_p2 >= 0;


minimize TotalInvestment:
  institutional + 
  direct_p1 + 
  direct_p2;


subject to BudgetLimit:
  institutional + 
  direct_p1 + 
  direct_p2 <= 10000;

subject to P1SalesIncrease:
  0.003 * institutional +
   0.004 * direct_p1 >= 30;

subject to P2SalesIncrease:
  0.003 * institutional + 
  0.01 * direct_p2 >= 30;