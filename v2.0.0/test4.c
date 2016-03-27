#include <stdio.h>

int main()
{
  int a, b, c[10], i;
  a = 197;

  if(a < 100)
    b = 134;
  else
    b = 26;

  for(i = 0; i < 3; i++)
    c[i] = a + b;

  a = c[2] + 18;
  return b;
}
