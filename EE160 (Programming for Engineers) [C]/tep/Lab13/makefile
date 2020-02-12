# makefile for Lab 13

# Problem 1 - Exploring arrays
averages: averages.o avg.o
	cc averages.o avg.o -o averages

# Problem 2 - Using arrays
water: water.o reading.o meter.o
	cc water.o reading.o meter.o -o water


#source file dependencies

averages.o: avg.h

water.o: meter.h reading.h

reading.o: water.h

meter.o: water.h


# utility targets

clean:
	rm  -f *.o
             
real_clean: clean
	rm  -f averages water a.out core
