#include "word.h"

Word::Word(int addres): address(addres)
{
} // constructor

Word::~Word()
{
} // destructor

bool Word::operator<(const Word &word) const
{
  if(address < word.address)
    return 1;
  else // is not less than
    return 0;
} // < operator