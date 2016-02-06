CPU.out: main.o decoder.o reader.o registers.o
	g++ -Wall -o CPU.out -ansi main.o decoder.o reader.o registers.o
  
main.o: main.c decoder.h reader.h registers.h instruction.h main.h
	g++ -c -Wall -ansi main.c
  
decoder.o: decoder.c decoder.h main.h
	g++ -c -Wall -ansi decoder.c
  
reader.o: reader.c reader.h
	g++ -c -Wall -ansi reader.c

registers.o: registers.c registers.h
	g++ -c -Wall -ansi registers.c

clean:
	rm CPU.out main.o decoder.o reader.o registers.o