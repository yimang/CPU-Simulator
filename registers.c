#include "registers.h"

// 7.3 Initializing values
int init_regs(Registers *registers, int *memory)
{
    registers->regs[esp] = 1000;
    registers->regs[ebp] = 996;
    registers->regs[eip] = 100;
    registers->regs[eax] = 0;
    memory[1000] = 0;
  
    return (0);
} // init_regs()
