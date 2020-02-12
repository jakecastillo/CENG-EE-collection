# target to make all programs for Lab 13
all: swap swapbig reorder
#Problem 1 - swap programs
#complete the dependency and action lines for your filenames
swap: swaptest.o swap.o
	cc swaptest.o swap.o -o swap

swaptest.o: swap.h

swap.o: swap.h

# Problem 2 - swapbig programs
swapbig:swapbig.o swap.o swapbigtest.o
	cc swap.o swapbig.o swapbigtest.o -o swapbig

swapbigtest.o: swapbig.h

swapbig.o: swapbig.h

#Problem 3 - reorder programs
reorder: reorder.o swap.o swapbig.o reordertest.o
	cc reorder.o reordertest.o swapbig.o swap.o -o reorder

reordertest.o: reorder.h

reorder.o: reorder.h

# source file dependencies
# add target lines showing dependencies for your .o files


 # utility targets

clean:
	rm -f *.o

real_clean: clean
	rm -f swap swapbig reorder
