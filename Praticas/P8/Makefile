# To compile all programs, run:
#   make
#
# JMR 2021, JMadeira 2023

# Options for the C compiler.
CFLAGS += -g -Wall -Wextra

TARGETS = Tests

all: $(TARGETS)

Date.o: Date.c Date.h

Person.o: Person.c Person.h Date.h

Tests.o: Tests.c Person.h Date.h PersonSet.h

Tests: Tests.o Person.o Date.o PersonSet.o

clean:
	rm -f *.o
	rm -f $(TARGETS)
	rm -f tst-*.txt

