# The two below are variables that can hold text.
# 
# You can use them by using $(NAME) to invoke them
# and replace the invokations with the variable contents.
INCLUDE_DIR=./include/

# The below are C++ compiler flags.
#
# -Wall, -Wextra, and -pedantic will cause the compiler
# to be more strict and emit warnings to make our code
# more safe.
#
# -std=c++11 is needed to use C++11 features, which we
# sometimes use for this class.
CXXFLAGS=-std=c++11 -Wall -Wextra -pedantic

all: ./bin/a1.out ./bin/a2.out ./bin/a3.out ./bin/b1.out ./bin/b2.out ./bin/b3.out

a1: ./bin/a1.out
a2: ./bin/a2.out
a3: ./bin/a3.out
b1: ./bin/b1.out
b2: ./bin/b2.out
b3: ./bin/b3.out

./bin/a1.out: ./src/minitasks/a1-virtual-functions.cpp
	g++ $(CXXFLAGS) -I$(INCLUDE_DIR) \
		./src/minitasks/a1-virtual-functions.cpp -o ./bin/a1.out
	./bin/a1.out

./bin/a2.out: ./src/minitasks/a2-abstract-base-classes.cpp
	g++ $(CXXFLAGS) -I$(INCLUDE_DIR) \
		./src/minitasks/a2-abstract-base-classes.cpp -o ./bin/a2.out
	./bin/a2.out

./bin/a3.out: ./src/a3-main.cpp ./include/BubbleSortVector.tcc
	g++ $(CXXFLAGS) -I$(INCLUDE_DIR) \
		./src/a3-main.cpp -o ./bin/a3.out
	./bin/a3.out

./bin/b1.out: ./src/minitasks/b1-class-templates.cpp
	g++ $(CXXFLAGS) -I$(INCLUDE_DIR) \
		./src/minitasks/b1-class-templates.cpp -o ./bin/b1.out
	./bin/b1.out

./bin/b2.out: ./src/minitasks/b2-function-templates.cpp
	g++ $(CXXFLAGS) -I$(INCLUDE_DIR) \
		./src/minitasks/b2-function-templates.cpp -o ./bin/b2.out
	./bin/b2.out

./bin/b3.out: ./src/b3-main.cpp ./include/string_conversion.hpp
	g++ $(CXXFLAGS) -I$(INCLUDE_DIR) \
		./src/b3-main.cpp -o ./bin/b3.out
	./bin/b3.out

clean: ./bin/*.out
	rm ./bin/*.out
