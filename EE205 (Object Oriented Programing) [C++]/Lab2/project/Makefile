all: bin/a.out

bin/a.out: src/main.o src/Point2D.o src/point_in_polygon.o src/Person.o
	g++ src/main.o src/Point2D.o src/point_in_polygon.o src/Person.o -o ./bin/a.out

src/main.o: src/main.cpp
	g++ -c src/main.cpp -o src/main.o

src/Point2D.o: src/Point2D.cpp
	g++ -c src/Point2D.cpp -o src/Point2D.o

src/point_in_polygon.o: src/point_in_polygon.cpp
	g++ -c src/point_in_polygon.cpp -o src/point_in_polygon.o

src/Person.o: src/Person.cpp
	g++ -c src/Person.cpp -o src/Person.o

test-all: test-Person test-Point2D test

test: bin/a.out
	./bin/a.out < ./tst/input.txt > a.txt
	diff ./a.txt ./tst/output.txt -u

test-Person: bin/test-Person.out
	./bin/test-Person.out

test-Point2D: bin/test-Point2D.out
	./bin/test-Point2D.out

bin/test-Person.out: src/Person.o src/Point2D.o tst/test-Person.cpp 
	g++ -I"src/" -o ./bin/test-Person.out tst/test-Person.cpp src/Person.o src/Point2D.o

bin/test-Point2D.out: src/Point2D.o tst/test-Point2D.cpp
	g++ -I"src/" -o ./bin/test-Point2D.out tst/test-Point2D.cpp src/Point2D.o
	
clean:
	rm ./src/*.o
	rm ./bin/*.out
	rm ./a.txt
