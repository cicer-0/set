#include "../include/set.hpp"
#include "../include/random.hpp"
#include "../include/print.hpp"
using namespace output;
int main(int argc, char *argv[])
{
	Set<int> setA("A"), setB("B"), setC("C"), result("Result");
	Color
			AColor{19, 141, 117},
			BColor{241, 196, 15},
			CColor{50, 120, 15},
			unionColor{231, 76, 60},
			intersectionColor{125, 60, 152},
			differenceColor{46, 134, 193};
	for (size_t i = 0; i < 10; i++)
		setA.add(RandomMath::numberInt(30));
	for (size_t i = 0; i < 10; i++)
		setB.add(RandomMath::numberInt(30));
	Print::wColorLn(Color(0, 0, 0), "Conjunto " + setA.getName() + ":");
	Print::wColorLn(AColor, setA.toString());
	Print::wColorLn(Color(0, 0, 0), "Conjunto " + setB.getName() + ":");
	Print::wColorLn(BColor, setB.toString());
	Print::wColorLn(Color(0, 0, 0), "Conjunto " + setC.getName() + ":");
	Print::wColorLn(CColor, setC.toString());

	result = setA + setB;
	Print::wColorLn(unionColor, result.toString());
	result = setA * setB * setC;
	Print::wColorLn(intersectionColor, result.toString());
	result = setA - setB;
	Print::wColorLn(differenceColor, result.toString());
	result = setB - setA;
	Print::wColorLn(differenceColor, result.toString());
	return 0;
}
