#include "CalcInChem_basics.h"

void CalcInChem_basics::Conversion::printScientific(double value, int significantDigits) {
	std::cout << std::scientific;
	std::cout << std::setprecision(significantDigits-1);
	std::cout << value;
}