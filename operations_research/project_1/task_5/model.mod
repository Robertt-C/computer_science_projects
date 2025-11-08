var large_factory_1 >= 0;
var large_factory_2 >= 0;
var large_factory_3 >= 0;
var medium_factory_1 >= 0;
var medium_factory_2 >= 0;
var medium_factory_3 >= 0;
var small_factory_1 >= 0;
var small_factory_2 >= 0;
var small_factory_3 >= 0;


maximize Profit:
  12 * (large_factory_1 + large_factory_2 + large_factory_3) +
  10 * (medium_factory_1 + medium_factory_2 + medium_factory_3) +
  9 * (small_factory_1 + small_factory_2 + small_factory_3);


subject to ProductionCapacityFactory1:
  large_factory_1 + 
  medium_factory_1 + 
  small_factory_1 <= 500;

subject to ProductionCapacityFactory2:
  large_factory_2 + 
  medium_factory_2 + 
  small_factory_2 <= 600;

subject to ProductionCapacityFactory3:
  large_factory_3 + 
  medium_factory_3 + 
  small_factory_3 <= 300;

subject to StorageConstraintFactory1:
  20 * large_factory_1 + 
  15 * medium_factory_1 + 
  12 * small_factory_1 <= 9000;

subject to StorageConstraintFactory2:
  20 * large_factory_2 + 
  15 * medium_factory_2 + 
  12 * small_factory_2 <= 8000;

subject to StorageConstraintFactory3:
  20 * large_factory_3 + 
  15 * medium_factory_3 + 
  12 * small_factory_3 <= 3500;

subject to LargeSalesLimit:
  large_factory_1 + 
  large_factory_2 + 
  large_factory_3 <= 600;

subject to MediumSalesLimit:
  medium_factory_1 + 
  medium_factory_2 + 
  medium_factory_3 <= 800;

subject to SmallSalesLimit:
  small_factory_1 + 
  small_factory_2 + 
  small_factory_3 <= 500;

subject to EqualPercentage1:
  (large_factory_1 + medium_factory_1 + small_factory_1) / 500 = 
  (large_factory_2 + medium_factory_2 + small_factory_2) / 600;

subject to EqualPercentage2:
  (large_factory_1 + medium_factory_1 + small_factory_1) / 500 = 
  (large_factory_3 + medium_factory_3 + small_factory_3) / 300;