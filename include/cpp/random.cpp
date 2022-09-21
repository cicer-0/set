#include "../random.hpp"
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
bool RandomMath::isSrand = false;
void RandomMath::RANDOMINIT()
{
  if (!isSrand)
    isSrand = true, srand(time(NULL));
}
string RandomMath::numberStr(unsigned short int length)
{
  RANDOMINIT();
  string number = "";
  unsigned short int digit = 0;
  for (int i = 0; i < length; i++)
  {
    digit = rand() % 10;
    if (!i)
      while (!digit)
        digit = rand() % 10;
    number += char(digit + 48);
  }
  return number;
}
unsigned int RandomMath::numberInt(unsigned int limit)
{
  RANDOMINIT();
  const unsigned int random = rand() % limit;
  return random;
}
int RandomMath::numberInt(int limitL, int limitR)
{
  if (limitR <= limitL)
    throw "invalid limits, the greater is the second parameter";
  RANDOMINIT();
  const int length = limitR - limitL;
  const int result = (rand() % length) + limitL;
  return result;
}
