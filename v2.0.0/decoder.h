#ifndef DECODER_H
#define	DECODER_H
// Author: Sean Davis

#include "instruction.h"
#include "registers.h"
#include "labels.h"

class Decoder
{
  char opcode[20];
  int *operand1;
  int *operand2;
  void addl(Registers *registers);
  void andl(Registers *registers);
  void call(Registers *registers, Memory &memory) const;
  void cmpl(Registers *registers) const;
  void incl(Registers *registers);
  void jg(Registers *registers) const;
  void jle(Registers *registers) const;
  void jmp(Registers *registers) const;  
  void leal(const Instruction& instruction, const Registers *registers);
  void leave(Registers *registers, const Memory &memory) const;
  void movl();
  void pushl(Registers *registers, Memory &memory) const;
  void ret(Registers *registers, const Memory &memory) const;
  void sall(Registers *registers);
  void subl(Registers *registers);
  void decl(Registers *registers) const; 
  void imull(Registers *registers); 
public:
  void execute(const Instruction& instruction, Registers *registers, 
               Memory &memory);
  void parse(const Instruction& instruction, Registers *registers, 
             Memory &memory, const Labels &labels);
}; // class Decoder;



#endif	// DECODER_H 

