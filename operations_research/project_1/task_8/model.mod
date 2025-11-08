var mineral_1 >= 0;
var mineral_2 >= 0;
var mineral_3 >= 0;
var mineral_4 >= 0;
var mineral_5 >= 0;


minimize Cost:
  mineral_1 * 8.5 +
  mineral_2 * 6.0 +
  mineral_3 * 8.9 +
  mineral_4 * 5.7 +
  mineral_5 * 8.8;


subject to LeadConstraint:
  0.3 * mineral_1 +
  0.1 * mineral_2 +
  0.5 * mineral_3 +
  0.1 * mineral_4 +
  0.5 * mineral_5 = 0.3 * (mineral_1 + mineral_2 + mineral_3 + mineral_4 + mineral_5);

subject to ZincConstraint:
  0.6 * mineral_1 +
  0.2 * mineral_2 +
  0.2 * mineral_3 +
  0.1 * mineral_4 +
  0.1 * mineral_5 = 0.2 * (mineral_1 + mineral_2 + mineral_3 + mineral_4 + mineral_5);

subject to TinConstraint:
  0.1 * mineral_1 +
  0.7 * mineral_2 +
  0.3 * mineral_3 +
  0.8 * mineral_4 +
  0.4 * mineral_5 = 0.5 * (mineral_1 + mineral_2 + mineral_3 + mineral_4 + mineral_5);

subject to TotalMixture:
  mineral_1 +
  mineral_2 +
  mineral_3 +
  mineral_4 +
  mineral_5 = 1;