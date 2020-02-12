# You can use variables in Makefiles in order to make all of the repetitive 
# typing much easier. Here, we include the C++11 version flag as well as 
# additional warning flags to make compilation stricter (and, thus, our programs 
# safer).
#
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11

SRC_DIR := ./src
OBJ_DIR := ./src
INCLUDE_DIRS := -I./dep/ -I./include/

# Here, we are calling functions available in GNU Make in order to get all of 
# the .o and .cpp files in ./src so we can use them in our rules later.
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: ./bin/test-Cashier.out ./bin/test-Cook.out ./bin/test-SupplyRunner.out ./bin/example-Cashier.out ./bin/example-Cook.out ./bin/example-SupplyRunner.out 

# This build each of the .cpp in the src dir into a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(INCLUDE_DIRS) $(CPPFLAGS) $(CXXFLAGS) -c -o  $@ $<

./bin/test-Cashier.out: $(OBJ_FILES) ./tst/test-Cashier.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-Cashier.out \
		./tst/test-Cashier.cpp $(OBJ_FILES)
	./bin/test-Cashier.out

./bin/test-Cook.out: $(OBJ_FILES) ./tst/test-Cook.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-Cook.out \
		./tst/test-Cook.cpp $(OBJ_FILES)
	./bin/test-Cook.out

./bin/test-SupplyRunner.out: $(OBJ_FILES) ./tst/test-SupplyRunner.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/test-SupplyRunner.out \
		./tst/test-SupplyRunner.cpp $(OBJ_FILES)
	./bin/test-SupplyRunner.out

./bin/example-Cashier.out: $(OBJ_FILES) ./tst/example-Cashier.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/example-Cashier.out \
		./tst/example-Cashier.cpp $(OBJ_FILES)
	./bin/example-Cashier.out

./bin/example-Cook.out: $(OBJ_FILES) ./tst/example-Cook.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/example-Cook.out \
		./tst/example-Cook.cpp $(OBJ_FILES)
	./bin/example-Cook.out

./bin/example-SupplyRunner.out: $(OBJ_FILES) ./tst/example-SupplyRunner.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/example-SupplyRunner.out \
		./tst/example-SupplyRunner.cpp $(OBJ_FILES)
	./bin/example-SupplyRunner.out

# Convenience rules for the command line to quickly test a class

cashier: ./bin/test-Cashier.out
cook: ./bin/test-Cook.out
runner: ./bin/test-SupplyRunner.out

excashier: ./bin/example-Cashier.out
excook: ./bin/example-Cook.out
exrunner: ./bin/example-SupplyRunner.out

clean:
	rm ./src/*.o
	rm ./bin/*.out

