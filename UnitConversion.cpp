/* 
Last Updated: 11/22/2015 by Neema Patel

convertTime Cases:
	1. millisecond
	2. second
	3. min
	4. hour
	5. day
	6. week

convertTemp Cases:
	1. Celsius
	2. Farenheit
	3. Kelvin

convertWeight Cases:
	1. milligram
	2. gram
	3. kilogram
	4. metric ton
	5. pound
	6. ounce
*/

#include <string>
#include <iostream>
using namespace std;

enum Time { MILLISECOND = 1, SECOND, MINUTE, HOUR, DAY, WEEK };
enum Temp { CELSIUS = 1, FARENHEIT, KELVIN };
enum Weight { MILLIGRAM, GRAM, KILOGRAM, TON, POUND, OUNCE};
 

double convertTime(int unitIn, int unitOut, double val) {
	double converted = 0.0;
	switch (unitIn) {									
	case MILLISECOND:										// converting milliseconds to...
		switch (unitOut) {							// ... milliseconds	
		case MILLISECOND:			
			converted = val; break;
		case SECOND:										// ...seconds
			converted = val / 1000.0; break;
		case MINUTE:										// ...minutes
			converted = val / (1000.0 * 60.0); break;
		case HOUR:										// ...hours
			converted = val / (1000.0 * 60.0 * 60.0); break;
		case DAY:										// ...days
			converted = val / (1000.0 * 60.0 * 60.0 * 24.0); break;
		case WEEK:										// ...weeks
			converted = val / (1000.0 * 60.0 * 60.0 * 24.0 * 7.0); break;
		default: 
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case SECOND:										// converting seconds to...
		switch (unitOut) {
		case MILLISECOND:									// millisec
			converted = val * 1000; break;
		case SECOND:									// sec
			converted = val; break;
		case MINUTE:									// min
			converted = val / 60.0; break;
		case HOUR:									// hr
			converted = val / (60.0 * 60.0); break;
		case DAY:									// days
			converted = val / (60.0 * 60.0 * 24.0); break;
		case WEEK:									// weeks
			converted = val / (60.0 * 60.0 * 24.0 * 7.0); break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case MINUTE:
		switch (unitOut) {						// converting minutes to...
		case MILLISECOND:									// milliseconds
			converted = val * (1000.0 * 60.0); break;
		case SECOND:									// seconds
			converted = val * 60.0; break;
		case MINUTE:									// minutes
			converted = val; break;
		case HOUR:									// hours
			converted = val / 60.0; break;
		case DAY:									// days
			converted = val / (60.0 * 24.0); break;
		case WEEK:									// weeks
			converted = val / (60.0 * 24.0 * 7.0); break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case HOUR:										// converting hours to...
		switch (unitOut) {break;
		case MILLISECOND:									// milliseconds
			converted = val * (1000.0 * 60.0 * 60.0); break;
		case SECOND:									// seconds
			converted = val * (60.0 * 60.0); break;
		case MINUTE:									// minutes
			converted = val * 60.0; break;
		case HOUR:									// hours
			converted = val; break;
		case DAY:									// days
			converted = val / 24.0; break;
		case WEEK:									// weeks
			converted = val / (24.0 * 7.0); break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case DAY:
		switch (unitOut) {						// converting days to...
		case MILLISECOND:									// milliseconds
			converted = val * (24.0 * 60.0 * 60.0 * 1000.0); break;
		case SECOND:									// seconds
			converted = val * (24.0 * 60.0 * 60.0); break;
		case MINUTE:									// minutes
			converted = val * (24.0 * 60.0); break;
		case HOUR:									// hours
			converted = val * 24.0; break;
		case DAY:									// days
			converted = val; break;
		case WEEK:									// weeks
			converted = val / 7.0; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case WEEK:									// converting weeks to...
		switch (unitOut) {
		case MILLISECOND:									// milliseconds
			converted = val * (7.0 * 24.0 * 60.0 * 60.0 * 1000.0); break;
		case SECOND:									// seconds
			converted = val * (7.0 * 24.0 * 60.0 * 60.0); break;
		case MINUTE:									// minutes
			converted = val * (7.0 * 24.0 * 60.0); break;
		case HOUR:									// hours
			converted = val * (7.0 * 24.0); break;
		case DAY:									// days
			converted = val * 7.0; break;
		case WEEK:									// weeks
			converted = val; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	default: 
		cout << "Error: invalid conversion input"; break;
	}


	return converted;
}

double convertTemp(int unitIn, int unitOut, double val) {			// add in error if temp in kelvin less than 0
	double converted = 0.0;
	switch (unitIn) {
	case CELSIUS:
		switch (unitOut) {
		case CELSIUS:
			converted = val; break;
		case FARENHEIT:
			converted = (val*9.0 / 5.0) + 32.0; break;
		case KELVIN:
			converted = val + 273.15; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case FARENHEIT:
		switch (unitOut) {
		case CELSIUS:
			converted = 5.0 / 9.0 * (val - 32.0); break;
		case FARENHEIT:
			converted = val; break;
		case KELVIN:
			converted = (5.0 / 9.0 * (val - 32.0)) + 273.15; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case KELVIN:
		switch (unitOut) {
		case CELSIUS:
			converted = val - 273.15; break;
		case FARENHEIT:
			converted = 5.0 / 9.0 * ((val - 273.14) - 32.0); break;
		case KELVIN:
			converted = val; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	default:
		cout << "Error: invalid conversion input"; break;
	}

	return converted;
}   

double convertWeight(int unitIn, int unitOut, double val) {
	double converted = 0.0;

	switch (unitIn) {
	case MILLIGRAM:									// convert milligrams			
		switch (unitOut) {							
		case MILLIGRAM:
			converted = val; break;
		case GRAM:										
			converted = val / 1000.0; break;
		case KILOGRAM:										
			converted = val / (1000.0 * 1000.0) ; break;
		case TON:										
			converted = val / (1000.0 * 1000.0 * 1000.0); break;
		case POUND:										
			converted = val * (2.205 / 1000.0); break;
		case OUNCE:										
			converted = val * (16 * 2.205) / (1000.0 * 1000.0) ; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case GRAM:										// convert grams
		switch (unitOut) {
		case MILLIGRAM:
			converted = val * 1000.0; break;
		case GRAM:
			converted = val; break;
		case KILOGRAM:
			converted = val / 1000.0; break;
		case TON:
			converted = val / (1000.0 * 1000.0); break;
		case POUND:
			converted = val * 2.205 / 1000; break;
		case OUNCE:
			converted = val * (16.0 * 2.205) / 1000.0; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case KILOGRAM:
		switch (unitOut) {						// converting kilograms
		case MILLIGRAM:
			converted = val * (1000.0 * 1000.0); break;
		case GRAM:
			converted = val * 1000.0; break;
		case KILOGRAM:
			converted = val; break;
		case TON:
			converted = val / 1000.0; break;
		case POUND:
			converted = val * 2.205; break;
		case OUNCE:
			converted = val * (2.205 * 16.0); break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case TON:										// converting metric tons
		switch (unitOut) {
		case MILLIGRAM:
			converted = val * 1000.0 * 1000.0 * 1000.0; break;
		case GRAM:
			converted = val * 1000.0 * 1000.0; break;
		case KILOGRAM:
			converted = val * 1000.0; break;
		case TON:
			converted = val; break;
		case POUND:
			converted = val * 2.205 * 1000.0; break;
		case OUNCE:
			converted = val * 2.205 * 16.0 * 1000.0; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case POUND:
		switch (unitOut) {						// converting pounds
		case MILLIGRAM:
			converted = val * (1000.0 * 1000.0) / 2.205; break;
		case GRAM:
			converted = val * 1000.0 / 2.205; break;
		case KILOGRAM:
			converted = val / 2.205; break;
		case TON:
			converted = val / (2.205 * 1000.0); break;
		case POUND:
			converted = val; break;
		case OUNCE:
			converted = val * 16.0; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	case OUNCE:									// converting ounces
		switch (unitOut) {
		case MILLIGRAM:
			converted = val * (1000.0 * 1000.0) / (2.205 * 16.0); break;
		case GRAM:
			converted = val * 1000.0 / (2.205 * 16.0); break;
		case KILOGRAM:
			converted = val / (2.205 * 16.0); break;
		case TON:
			converted = val / (1000.0 * 2.205 * 16.0); break;
		case POUND:
			converted = val / 16.0; break;
		case OUNCE:
			converted = val; break;
		default:
			cout << "Error: invalid conversion output"; break;
		}
		break;
	default:
		cout << "Error: invalid conversion input"; break;
	}

	return converted;

}

int main() {
	cout << "10000 seconds to " << convertTime(SECOND,HOUR,10000.0) << " hours" << endl;
	cout << "300.3 K to " << convertTemp(KELVIN, CELSIUS, 300.3) << " C" << endl;
	cout << "200 lbs to " << convertWeight(POUND, KILOGRAM, 200) << " kg" << endl;
	return 0;
}