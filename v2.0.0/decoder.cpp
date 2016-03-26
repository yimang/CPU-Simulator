// Author: Sean Davis
#include <cstring>
#include <iostream>
#include <cstdlib>
#include "decoder.h"
#include "instruction.h"
#include "registers.h"
#include "data.h"
#include "memory"
using namespace std;

void Decoder::addl(Registers *registers)
{
  *operand2 = *operand1 + *operand2;
   registers->setFlags(*operand2);
}  // addl()


void Decoder::andl(Registers *registers)
{
  *operand2 = *operand1 & *operand2;
  registers->setFlags(*operand2);
}  // andl()


void Decoder::call(Registers *registers, Memory &memory) const
{
  Data &data = dynamic_cast <Data&>(memory[*registers += -4]);
  data = registers->get(Registers::eip);
  registers->set(Registers::eip, *operand1);
} // call()


void Decoder::cmpl(Registers *registers) const
{
  registers->setFlags(*operand2 - *operand1);
}  // cmpl()


void Decoder::execute(const Instruction& instruction,
                      Registers *registers, Memory &memory)
{
  const char *opcodes[] = { "addl", "andl", "leave", "movl", "pushl", "ret",
    "subl", "cmpl", "incl", "jg", "jle", "jmp", "leal", "call", "sall", 
    "decl", "imull" };
  enum OpcodeNum 
    {ADDL, ANDL, LEAVE, MOVL, PUSHL, RET, SUBL, CMPL, INCL, JG,
      JLE, JMP, LEAL, CALL, SALL, DECL, IMULL
    };  // enum OpcodeNum
  int opcodeNum;
  
  for(opcodeNum = ADDL; 
    strcmp(opcode, opcodes[opcodeNum]) != 0 || opcodeNum > IMULL;
    ++opcodeNum);
  
  switch (opcodeNum)
  {
    case ADDL: addl(registers); break;
    case ANDL: andl(registers); break;
    case LEAVE: leave(registers, memory); break;
    case MOVL: movl(); break;
    case PUSHL: pushl(registers, memory); break;
    case RET: ret(registers, memory); break;
    case SUBL: subl(registers); break;
    case CMPL: cmpl(registers); break;
    case INCL: incl(registers); break;
    case JG: jg(registers); break;
    case JLE:  jle(registers); break;
    case JMP: jmp(registers); break;
    case LEAL: leal(instruction, registers); break;
    case CALL: call(registers, memory); break;
    case SALL: sall(registers); break;
    case DECL: decl(registers); break;
    case IMULL: imull(registers); break;
    default: cout << "Invalid opcode!\n";
  } // switch on oncodeNum
 
}  // execute()


void Decoder::incl(Registers *registers)
{
  registers->setFlags(++(*operand1));
}  // incl()


void Decoder::jg(Registers *registers) const
{
  if(!registers->getSF() && !registers->getZF())
    registers->set(Registers::eip, *operand1);
} // jg()


void Decoder::jle(Registers *registers) const
{
  if(registers->getSF() || registers->getZF())
    registers->set(Registers::eip, *operand1);
}  // jle()


void Decoder::jmp(Registers *registers) const
{
  registers->set(Registers::eip, *operand1);
}  // jmp()


void Decoder::leal(const Instruction& instruction, const Registers *registers)
{
  
  char *ptr, info[1000];
  Registers::RegName reg;
  
  strcpy(info, instruction.getInfo());
  strtok(info, " ");  // get past leal
  ptr = strtok(NULL, " ");
  
  reg = (Registers::RegName) registers->stringToRegNum(ptr);  
  *operand2 = atoi(ptr) + registers->get(reg);
}  // leal()


void Decoder::leave(Registers *registers, const Memory &memory) const
{
  registers->set(Registers::esp, registers->get(Registers::ebp));
  const Data &data = dynamic_cast <const Data&>
    (memory[registers->get(Registers::esp)]);
  registers->set(Registers::ebp, data.get());
  *registers += 4;
}  // leave()


void Decoder::movl()
{
  *operand2 = *operand1;
}  // movl()


void Decoder::parse(const Instruction &instruction, Registers *registers, 
                    Memory &memory, const Labels &labels)
{
  char *ptr, info[1000];
  
  strcpy(info, instruction.getInfo());
  strcpy(opcode, strtok(info, " "));
  ptr = strtok(NULL, " ");
  
  if(ptr)
  {
    operand1 = registers->address(ptr, memory, labels);
    ptr = strtok(NULL, " ");
    
    if(ptr)
      operand2 = registers->address(ptr, memory, labels);
  } // if there is at least one operand
}  // parse()





void Decoder::pushl(Registers *registers, Memory &memory) const
{
  Data &data = dynamic_cast <Data&>(memory[*registers += -4]);
  data = *operand1;
}  // pushl()




void Decoder::ret(Registers *registers, const Memory &memory) const
{
  const Data &data = dynamic_cast <const Data&>
    (memory[registers->get(Registers::esp)]);
  registers->set(Registers::eip, data.get());
  *registers += 4;
}  // ret()


void Decoder::sall(Registers *registers)
{
  *operand2 <<= *operand1;
  registers->setFlags(*operand2);
}  // sall()


void Decoder::subl(Registers *registers)
{
  *operand2 = *operand2 - *operand1;
  registers->setFlags(*operand2);
}  // subl()

void Decoder::decl(Registers *registers) const
{
  registers->setFlags(--*operand1);
} // decl()

void Decoder::imull(Registers *registers) 
{  
  *operand2 = *operand1 * *operand2;
  registers->setFlags(*operand2);
} // imull()
