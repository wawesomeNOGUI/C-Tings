#include <iostream>
#include <cstdarg>

void doubleLy(double x) {
  std::cout << x << "\n";
}

//takes as the first argument the number of following arguments
void printNums(int count, ...)      // C-style "const char* fmt, ..." is also valid
{
    va_list ap;

    //Initializes ap to retrieve the additional arguments after parameter count
    va_start(ap, count);

    for (double i = 0; i < count; i++) {
      //std::cout << va_arg(ap, int) << "\n";
      doubleLy(va_arg(ap, int));
    }

    va_end(ap);
}

int main()
{
    printNums(6, 1, 2, -3, 4, 5, -10);
  //  doubleLy(5);
}
