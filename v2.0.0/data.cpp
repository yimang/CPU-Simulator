#include "data.h"

Data::Data(int addres) : Word(addres)
{
} // constructor

int& Data::get()
{
  return num;
} // get()

const int& Data::get() const
{
  return num;
} // const get()

int Data::operator=(int value)
{
  num = value;
  
  return value;
} // assignment =