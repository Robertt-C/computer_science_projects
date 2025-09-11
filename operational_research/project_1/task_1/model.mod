var barley >= 0;
var oat >= 0;
var soy >= 0;
var corn >= 0;


minimize Cost:
  (30 * barley) + (48 * oat) + (44 * soy) + (56 * corn);


subject to TotalAmount:
  barley + oat + soy + corn = 10000;

subject to ProteinQuantity:
  (0.069 * barley) + (0.085 * oat) + (0.09 * soy) + (0.271 * corn) = 1500;

subject to fat:
  (0.06 * barley) + (0.11 * oat) + (0.11 * soy) + (0.14 * corn) >= 800;

subject to MinimumCalories:
  (1760 * barley) + (1700 * oat) + (1056 * soy) + (1400 * corn) >= 11000000;

subject to MaximumCalories:
  (1760 * barley) + (1700 * oat) + (1056 * soy) + (1400 * corn) <= 22500000;

subject to MinimumCorn:
  corn >= 2000;

subject to MaximumSoy:
  soy <= 1200;