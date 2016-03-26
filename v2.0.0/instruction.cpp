#include "instruction.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Instruction::Instruction(int addres) : Word(addres), info(NULL)
{
}  // Instruction()


Instruction::~Instruction()
{
  if(info)
    delete [] info;
}  // ~Instruction
  
const char* Instruction::getInfo() const
{
  return info;
} // get()


void Instruction::operator=(const char* information)
{
  info = new char[strlen(information) + 1];
  strcpy(info, information);
} // setInfo()

ostream& operator<<(ostream& os, const Instruction& instruction)
{
  os << left << setw(20) << instruction.getInfo();
  return os;
} // << insertion