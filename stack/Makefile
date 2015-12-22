all: ll-stacktest ar-stacktest
ll-stacktest: ll-stack.h ll-stacktest.cc
	g++ -std=c++11 -o ll-stacktest ll-stacktest.cc
ar-stacktest: ar-stack.h ar-stacktest.cc
	g++ -std=c++11 -o ar-stacktest ar-stacktest.cc
clean:
	rm ll-stacktest ar-stacktest
rm:
	rm *~ .*~
