#include <stdio.h>

int foo(int x, int y)
{
  return x + y;
} // foo

void twice(int *z)
{
  *z = *z * 2;
}

int main()
{
  int a, b, c;
  a = 7;
  b = 15;
  c = foo(a , 31);
  twice(&b);
  
  return c;
}
