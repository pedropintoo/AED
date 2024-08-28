
# Options for the C compiler. 
CFLAGS += -g -Wall -Wextra

TARGETS = Main

all: $(TARGETS)


PointersQueue.o: PointersQueue.c PointersQueue.h

PointersStack.o: PointersStack.c PointersStack.h

Date.o: Date.c Date.h

Person.o: Person.c Person.h Date.h

Main.o: Main.c Date.h Person.h PointersStack.h PointersQueue.h

Main: Main.o Date.o Person.o PointersStack.o PointersQueue.o

clean:
	rm -f *.o
	rm -f $(TARGETS)

