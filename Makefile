# Ryan Carlson, ID 918062981

all:
	make checkpack
	make testPoint
	make testShape

checkpack: Domain.o Point.o Shape.o checkpack.cpp
	g++ -Wall -o $@ $^

testPoint: Point.o testPoint.cpp
	g++ -Wall -o $@ $^

testShape: Shape.o Point.o testShape.cpp
	g++ -Wall -o $@ $^

clean:
	rm -f checkpack testPoint testShape *.o
