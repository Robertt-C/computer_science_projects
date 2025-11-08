var short_range >= 0 integer;
var medium_range >= 0 integer;
var long_range >= 0 integer;


maximize Profit:
  short_range * 0.23 +
  medium_range * 0.30 +
  long_range * 0.42;


subject to BudgetConstraint:
  short_range * 3.5 +
  medium_range * 5 +
  long_range * 6.7 <= 150;

subject to PilotsConstraint:
  short_range +
  medium_range +
  long_range <= 30;

subject to MaintenanceConstraint:
  short_range * 1 +
  medium_range * (4/3) +
  long_range * (5/3) <= 40;