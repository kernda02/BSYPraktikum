# ---------------------------------------------------------------------------
# Makefile fuer Programmbeispiel mit searaten Dateien
# Fach:     BS
# Changes:  J. Zeman, M. Thaler
# File:     makefile 
# Stand:    03/2017
# ---------------------------------------------------------------------------

# Macros

PROFI =
CC    = gcc -std=gnu99
CFLGS = -g -Wall $(PROFI)

doit:
		@make --no-print-directory test1
		@make --no-print-directory test2

main:		main.o mlist.o mthread.o 
		$(CC) $(CFLGS) main.o mlist.o mthread.o -o $@.e

test1:		test1.o mlist.o mthread.o 
		$(CC) $(CFLGS) test1.o mlist.o mthread.o -o $@.e

test2:		test2.o mlist.o mthread.o 
		$(CC) $(CFLGS) test2.o mlist.o mthread.o -o $@.e

leakTest:		
		rm -f test3.e
		make --no-print-directory MtestM

MtestM:
		$(CC) test3.c mlist.c mthread.c -o test3.e

profileTest:
		rm -f *.o 
		@make --no-print-directory PtestP PROFI="-pg -no-pie"

PtestP:		test4.o mlist.o mthread.o 
		$(CC) $(CFLGS) $(PROFI) test4.o mlist.o mthread.o -o test4.e


.c.o:		$< mlist.h  mthread.h
		$(CC) $(CFLGS) -c $< -o $*.o

clean:		
		rm -f *.e *.o
		@echo "directory cleaned"

all:
		@rm -f *.o
		make --no-print-directory test1
		make --no-print-directory test2
#-----------------------------------------------------------------------------
