#include "../include/set.hpp"
#include "../include/random.hpp"
#include "../include/print.hpp"
#include <list>
using namespace output;
int main(int argc, char *argv[])
{
	list<string> s = list<string>();
	Set<int> setA, setB, result;
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

	Print::wColorLn(Color(0, 0, 0), "Conjunto A:");
	Print::wColorLn(AColor, setA.toString());
	Print::wColorLn(Color(0, 0, 0), "Conjunto B:");
	Print::wColorLn(BColor, setB.toString());

	result = setA + setB;
	Print::wColorLn(unionColor, result.toString());
	result = setA * setB;
	Print::wColorLn(intersectionColor, result.toString());
	result = setA - setB;
	Print::wColorLn(differenceColor, result.toString());
	result = setB - setA;
	Print::wColorLn(differenceColor, result.toString());
	return 0;
}
