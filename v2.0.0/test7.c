
int fac(int n)
{
  if(n < 1)
    return 1;

  return n * fac(n - 1);
} // fac()


int main()
{
  int a, b, c = 4;

  a = fac(c);
  b = fac(3);
  return a + b;
} // main()
