#include "../include/place.hpp"
#include "../include/random.hpp"
#include "../include/print.hpp"
using namespace output;
int main(int argc, char *argv[])
{
	Place<int> setA, setB, result;

	Color
			AColor{19, 141, 117},
			BColor{241, 196, 15},
			unionColor{231, 76, 60},
			intersectionColor{125, 60, 152},
			differenceColor{46, 134, 193};

	for (size_t i = 0; i < 10; i++)
		setA.add(RandomMath::numberInt(30));
	for (size_t i = 0; i < 10; i++)
		setB.add(RandomMath::numberInt(30));

	Print::wColorLn(AColor, setA.toString());
	Print::wColorLn(BColor, setB.toString());
	result = setA + setB;
	Print::wColorLn(unionColor, result.toString());
	result = Place<int>::unionPlace(setA, setB);
	Print::wColorLn(unionColor, result.toString());
	result = setA * setB;
	Print::wColorLn(intersectionColor, result.toString());
	result = Place<int>::intersectionPlace(setA, setB);
	Print::wColorLn(intersectionColor, result.toString());
	result = setA - setB;
	Print::wColorLn(differenceColor, result.toString());
	result = Place<int>::differencePlace(setA, setB);
	Print::wColorLn(differenceColor, result.toString());
	return 0;
}
