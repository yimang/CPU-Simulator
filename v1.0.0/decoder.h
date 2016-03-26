#ifndef DECODER_H
#define DECODER_H
 
#include "registers.h"
#include "main.h"

typedef struct Decoder 
{
  char opcode[20];
  int *operand1;
  int *operand2;
} Decoder;
 
void execute(Decoder *decoder, Registers *registers, int memory[]);
void parse(Decoder *decoder, char *instruction, 
           Registers *registers, int memory[]);

#endif