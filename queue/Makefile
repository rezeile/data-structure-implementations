all: ll-queue ar-queue
ll-queue: ll-queue.h ll-queuetest.cc
	g++ -std=c++11 -o ll-queue ll-queuetest.cc
ar-queue: ar-queue.h ar-queuetest.cc
	g++ -std=c++11 -o ar-queue ar-queuetest.cc
clean:
	rm ar-queue ll-queue
rm:
	rm *~ .*~
