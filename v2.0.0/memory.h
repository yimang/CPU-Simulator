#ifndef MEMORY_H
#define	MEMORY_H

#include "word.h"
#include "instruction.h"

class Registers;
class Memory;

class ListNode
{
  friend class Memory;
  Word* word;
  ListNode* next;
public:
  ListNode(Word *wor, ListNode* listNode);
  ~ListNode();
}; // ListNode

class Memory 
{
  ListNode *head;
public:
  const Instruction& fetch(Registers *registers);
  Memory();
  ~Memory();
  Word& insert(Word* word);
  const Word& operator[] (int addres) const;
  Word& operator[] (int addres);
  friend istream& operator>> (istream &is, Memory &memory);
}; // Memory

#endif	// MEMORY_H

