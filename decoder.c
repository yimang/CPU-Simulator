#include "decoder.h"
#include <string.h>
#include <stdlib.h>

//3.3 Opcode
void addl(Decoder *decoder, Registers *registers, int memory[])
{
  *(decoder->operand2) = *(decoder->operand1) + *(decoder->operand2);
} // addl ()
    

void andl(Decoder *decoder, Registers *registers, int memory[])
{
  *(decoder->operand2) = *(decoder->operand1) & *(decoder->operand2);
} // andl ()


void leave(Decoder *decoder, Registers *registers, int memory[])
{
  registers->regs[esp] = registers->regs[ebp];
  registers->regs[ebp] = memory[registers->regs[esp]];
  registers->regs[esp] += 4;
} // leave ()


void movl(Decoder *decoder, Registers *registers, int memory[])
{
  *(decoder->operand2) = *(decoder->operand1);
} // movl ()


void pushl(Decoder *decoder, Registers *registers, int memory[])
{
  registers->regs[esp] -= 4;
  memory[registers->regs[esp]] = *(decoder->operand1);
} // pushl ()


void ret(Decoder *decoder, Registers *registers, int memory[])
{
  registers->regs[eip] = memory[registers->regs[esp]];
  registers->regs[esp] += 4;
} // ret ()


void subl(Decoder *decoder, Registers *registers, int memory[])
{
  *(decoder->operand2) = *(decoder->operand2) - *(decoder->operand1);
} // subl ()


void parse(Decoder *decoder, char *instruction, 
           Registers *registers, int memory[])
{
  char *tok;
  char *instruction_copy;

  instruction_copy = (char*) malloc(strlen(instruction) + 1);
  strcpy(instruction_copy, instruction);

  if ((tok = strtok(instruction_copy, " ,")))  //store first token in opcode
    strcpy(decoder->opcode, tok);

  if ((tok = strtok(NULL, " ,")))  //store second token in operand1 if exists
    decoder->operand1 = address(registers, tok, memory);

  if ((tok = strtok(NULL, " ,")))  //store third token in operand2 if exists
    decoder->operand2 = address(registers, tok, memory);  
} // parse ()


//7.5.3 Execute decoder
void execute(Decoder *decoder, Registers *registers, int memory[])
{
  if(strcmp(decoder->opcode, "addl") == 0) // for addl
    addl(decoder, registers, memory);

  else // for andl
    if(strcmp(decoder->opcode, "andl") == 0) 
    andl(decoder, registers, memory);

  else // for leave
    if(strcmp(decoder->opcode, "leave") == 0) 
    leave(decoder, registers, memory);

  else // for movl
    if(strcmp(decoder->opcode, "movl") == 0) 
    movl(decoder, registers, memory);

  else // for pushl
    if(strcmp(decoder->opcode, "pushl") == 0) 
    pushl(decoder, registers, memory);

  else // for ret
    if(strcmp(decoder->opcode, "ret") == 0) 
    ret(decoder, registers, memory);

  else // for subl
    if(strcmp(decoder->opcode, "subl") == 0) 
    subl(decoder, registers, memory);
} // execute ()