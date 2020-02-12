# makefile for Lab 12

# Problem 1 - exploring pointers
swap: swaptest.o swap.o
	cc swaptest.o swap.o -o swap

# Problem 2 - using pointers
swapbig: swapbigtest.o swap.o
	cc swapbigtest.o swap.o -o swapbig

# Problem 3 - more pointers and functions
reorder: swapreordertest.o swap.o
	cc swapreordertest.o swap.o -o reorder

# source file dependencies
swaptest.o: swap.h
swapbigtest.o: swap.h
swapreordertest.o: swap.h

# utility targets
clean:
	rm  -f *.o

real_clean: clean
	rm  -f swap swapbig reorder a.out core
