
# target to make all programs for Lab 9
all: mygrader mygrader2 countgrades

# Problem 1 - grader programs
#	complete the dependency and action lines for your filenames
mygrader: grader.o lettergrade.o 
	cc grader.o lettergrade.o -o mygrader

mygrader2: grader2.o lettergrade2.o
	cc grader2.o lettergrade2.o -o mygrader2

# Problem 2 - grade counter
countgrades: countgrades.o
	cc countgrades.o -o countgrades

# source file dependencies
#	add target lines showing dependencies for your .o files


# utility targets

clean:
	rm -f *.o

real_clean: clean
	rm -f mygrader mygrader1 countgrades

