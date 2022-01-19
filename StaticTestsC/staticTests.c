#include <stdio.h>

//static functions can't be used from another file
static void printBitwiseOr(int x)
{
  static int y;  //static variables stay in memory even after function returns
  y = x | y;
  printf("Bitwise Or = %i \n", y);
}


int main()
{
  for (int i = 0; i < 25; i++)
  {
    printBitwiseOr(i);
  }
}
