#include <cstdlib>
#include <iostream>
#include <cstring>
#include "memory.h"
#include "word.h"
#include "data.h"
#include "registers.h"

using namespace std;

const Instruction& Memory::fetch(Registers *registers)
{
  int pos = registers->get(Registers::eip);
  const Instruction& instruction = dynamic_cast<Instruction&>((*this)[pos]);
  registers->set(Registers::eip, registers->get(Registers::eip) + 4);
  return instruction;
} // fetch()

istream& operator>> (istream &is, Memory &memory)
{
  char line[256], *ptr;
  int address = 100;
  Instruction* instruction;
  
  while(is.getline(line, 256))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters
    
    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
    
    if(*ptr != '.' && *ptr != '_' && 
       !strstr(line, "main:") && !strchr(line, ':'))
    {
      instruction = new Instruction(address);
      address += 4;
      *instruction = ptr;
      memory.insert(instruction);
    } // if not directive, nor main:
  }  // while more in file
  
  return is;
}  // operator>>


Memory::Memory() : head(NULL)
{
} // constructor

Memory::~Memory()
{
  ListNode *ptr;
  
  for(ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  } // delete listNodes
} // destructor

ListNode::ListNode(Word* wor, ListNode *listNode)
{
  word = wor;
  next = listNode;
} // constructor

ListNode::~ListNode()
{
  delete word; 
} // destructor

Word& Memory::insert(Word* word)
{
  ListNode *ptr, *pre = NULL;
  
  for (ptr = head; ptr && *(ptr->word) < *word; ptr = ptr->next)
    pre = ptr;
  
  if (pre)
  {
    pre->next = new ListNode(word, ptr);
    return *(pre->next->word);
  } // for not new head
  
  head = new ListNode(word, ptr);
  return *(head->word);
} // insert

const Word& Memory::operator[] (int addres) const
{
  ListNode *ptr;
  Word temp(addres); 
  
  for (ptr = head; ptr && *(ptr->word) < temp; ptr = ptr->next);
     
  if (!ptr || temp < *(ptr->word))
  {
    cout << "Seg fault at address: " << addres << endl;
    exit(1);
  } // cannot fail const
    
  return *(ptr->word);
} // const []

Word& Memory::operator[] (int addres)
{
  ListNode *ptr;
  Word temp(addres); 
  
  for (ptr = head; ptr && *(ptr->word) < temp; ptr = ptr->next);
  
  if (!ptr || temp < *(ptr->word))
  {
    Data *data = new Data(addres);
    return insert(data);
  } // insert
  
  return *(ptr->word);
} // [] operation