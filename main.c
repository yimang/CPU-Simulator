#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "instruction.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int* address(Registers *registers, char *operand, int memory[])
{
  static int value;
  char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
  char *ptr;
  int regNum, index;

  if(operand == NULL)
    return NULL;

  if(operand[0] == '$') // immediate mode
  {
    value = atoi(&operand[1]);
    return &value;
  } // if immediate mode

  for(regNum = eax; regNum <= eip; regNum++)
    if(strstr(operand, regNames[regNum]))
      break;

  ptr = strchr(operand, '(');
  
  if(ptr) // some form of indirect addressing
  {
    *ptr = '\0';  // terminate operand string at first '('
    index = atoi(operand);  // will return 0 if no number there!
    return  &memory[registers->regs[regNum] + index];
  } // if ptr
  else  // direct addressing
    return &(registers->regs[regNum]);

} // address ()

int main(int argc, char* argv[])
{
    //7.1-7.2 Declarations
    Reader reader;
    Decoder decoder;
    Registers registers;
    int memory[1001];
    FILE *fp;
    char *instruction; // holds current instruction
  
    fp = fopen(argv[1], "r");
    init_regs(&registers, memory); //7.3 Initializing values
    read(fp, &reader);

    //7.5 Call Functions?
    while (registers.regs[eip] != 0)  // run until eip is zero
    {

        instruction = fetch(&reader, &registers); // function in ???
        parse(&decoder, instruction, &registers, memory);
        execute(&decoder, &registers, memory); // executes opcode in decoder
        print_status(&reader, &registers);

    } // call functions to run instructions
  
    fclose(fp);
    return (0);
}  // main()
