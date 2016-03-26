#ifndef INSTRUCTION2_H
#define	INSTRUCTION2_H

class Instruction2
{
  int address;
  char *info;
public:
  Instruction2();
  ~Instruction2();
  int getAddress() const;
  const char* getInfo() const;
  void setAddress(int addr);
  void setInfo(const char* information);
  
}; //class Instruction2

#endif	// INSTRUCTION2_H 

