#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reader.h"
#include "registers.h"

void strtokRead (Reader *reader, char *token, unsigned int *i, 
                 int *boolean, int *lineNum, int *address) 
{
  for (*i = 0; *i < strlen(token); (*i)++) 
    {
      if (token[*i] == '.' || (token[*i] == 'm' && token[*i + 1] == 'a'))
      {
        *boolean = 1;
        break;
      } // ignores directives and main
    } // parses through token

    if (*boolean == 0) 
    {
      reader->lines[*lineNum].info = token;
      reader->lines[(*lineNum)++].address = *address;
      *address += 4;
    } // puts into reader

    *boolean = 0;
} // strtokRead ()


int read (FILE *fp, Reader *reader)
{
  char *buffer, *temp, *token; 
  int length, address = 100, lineNum = 0, boolean = 0; 
  unsigned int i; 

  fseek(fp, 0, SEEK_END); // Finds the length of the file
  length = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  buffer = (char*) malloc(length + 1); // + 1 for the null character
  temp = buffer; // temp starts off at the same location in memory

  while(fgets(temp, length, fp)) // Transfers the contents to buffer
    temp += strlen(temp);

  for (i = 0; i < strlen(buffer); i++)
      if (buffer[i] == '\t') // if tab char
      {
        buffer[i] = ' ';
      } // Changes the tab characers to spaces
    
  if ((token = strtok(buffer, "\n"))) // Stores each instruction
      strtokRead (reader, token, &i, &boolean, &lineNum, &address);
    
  while ((token = strtok(NULL, "\n"))) // Continuation of strtok process
      strtokRead (reader, token, &i, &boolean, &lineNum, &address);

  return (0);
} // read ()


char *fetch(Reader *reader, Registers *registers)
{
    int i;

    for (i = 0; reader->lines[i].address != 0; i++)
    {
      if (reader->lines[i].address == registers->regs[eip])
      {
        break;
      }// match address to eip
    }// walk until match fulfilled

    registers->regs[eip] += 4;
    return (reader->lines[i].info);
} // fetch ()


void print_status(Reader *reader, Registers *registers)
{
    int i;

    if (registers->regs[eip] == 0)
    {
        printf("%-20s eip: %3d eax: %3d ebp: %3d esp: %3d\n", "ret",
               registers->regs[eip], registers->regs[eax],
               registers->regs[ebp], registers->regs[esp]);
    }// only when done
  
    else // when not done
    {
      for (i = 0; reader->lines[i].address != 0; i++)
      {
        if (reader->lines[i].address == registers->regs[eip] - 4)
        {
          break;
        } // leave when new line
      } // walk to next

        printf("%-20s eip: %3d eax: %3d ebp: %3d esp: %3d\n",
               reader->lines[i].info + 1, registers->regs[eip],
               registers->regs[eax], registers->regs[ebp],
               registers->regs[esp]);
    } // else
} // print_status ()
