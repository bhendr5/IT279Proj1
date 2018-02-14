CC=g++
CFLAGS=-c
OFLAG=-o

build: output

output: main.o linkedQueue.o
	${CC} main.o linkedQueue.o ${OFLAG} output
	
linkedQueue.o: linkedQueue.cpp linkedQueue.h
	${CC} ${CFLAGS} linkedQueue.cpp

main.o: main.cpp
	${CC} ${CFLAGS} main.cpp

clean: 
	- rm -rf *.o
