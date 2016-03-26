#ifndef WORD_H
#define	WORD_H

class Word
{
  int address;
public:
  Word(int addres);
  virtual ~Word();
  bool operator< (const Word &word) const;
}; // class Word

#endif	// WORD_H



