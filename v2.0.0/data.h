#ifndef DATA_H
#define	DATA_H

#include "word.h"

class Data: public Word 
{
  int num;
public:
  Data(int addres);
  int& get();
  const int& get() const;
  int operator=(int value);
}; // Data

#endif	// DATA_H


