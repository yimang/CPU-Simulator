#ifndef REGISTERS_H
#define REGISTERS_H

enum {eax, ebp, esp, eip};

typedef struct Registers 
{
  int regs[4];
} Registers;

int init_regs(Registers *registers, int *memory);

#endif