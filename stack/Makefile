all: ll-stack ar-stack
ll-stack: ll-stack.h stacktest.cc
	g++ -std=c++11 -o ll-stack stacktest.cc
ar-stack: ar-stack.h stacktest.cc
	g++ -std=c++11 -o ar-stack stacktest.cc
clean:
	rm ll-stack ar-stack
