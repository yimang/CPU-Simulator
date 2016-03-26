// Not sure about the members of this structure

#ifndef READER_H
#define READER_H

#include "instruction.h"
#include "registers.h"
#include <stdio.h>

typedef struct Reader 
{
  Instruction lines[1000];
  int address[1000];
} Reader;

int read (FILE *fp, Reader *reader);
char *fetch(Reader *reader, Registers *registers);
void print_status(Reader *reader, Registers *registers);

#endif