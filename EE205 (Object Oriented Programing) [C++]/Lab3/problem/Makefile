all: ./lib/libContainer.a

# This is the rule you need to fille out
./lib/libContainer.a:
	g++ -c ./src/Vector.cpp -o ./src/Vector.o
	g++ -c ./src/ListNode.cpp -o ./src/ListNode.o
	g++ -c ./src/List.cpp -o ./src/List.o
	ar rcs ./lib/libContainer.a ./src/Vector.o ./src/ListNode.o ./src/List.o

test-Vector: ./lib/libContainer.a ./tst/test-Vector.cpp
	g++ -o ./bin/test-Vector.out -I./include/ \
	./tst/test-Vector.cpp -L./lib/ -lContainer
	./bin/test-Vector.out

test-ListNode: ./lib/libContainer.a ./tst/test-ListNode.cpp
	g++ -o ./bin/test-ListNode.out -I./include/ \
	./tst/test-ListNode.cpp -L./lib/ -lContainer
	./bin/test-ListNode.out

test-List: ./lib/libContainer.a ./tst/test-List.cpp
	g++ -o ./bin/test-List.out -I./include/ \
	./tst/test-List.cpp -L./lib/ -lContainer
	./bin/test-List.out

test-all: test-Vector test-ListNode test-List

clean:
	rm ./lib/*.a
	rm ./bin/*.out
	rm ./src/*.o

