
int foo(int x, int y)
{
  return x - y;
} // foo

void thrice(int *z)
{
  *z = *z * 2;
}

int main()
{
  int a, b, c[5];
  a = 19;

  if(a < 10)
     b = 13;
  else
     b = 65;

  for(a = 0; a < 2; a++)
    c[a] = a + b;

  c[3] = foo(a , 31);
  thrice(&b);
  return b;
}
