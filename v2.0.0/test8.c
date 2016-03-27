int fib(int n)
{
  if(n < 2)
    return 1;

  return fib(n - 1) + fib(n - 2);
}  // fib()

int main()
{
  int a, b, c;

  a = 4;
  b = fib(a);
  c = fib(5);
  return b + c + a;
} // main()
