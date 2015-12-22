# Note that gcc is the GNU Compiler Collection and
# g++ is the compiler driver (for c++) [whatever that means]
# The -std flag sets the c++ standard to be C++11
# The -o specifies the output file name after compilation

all: ar-bagtest ll-bagtest
ar-bagtest: ar-bag.h bagtest-ar.cc
	g++ -std=c++11 -o ar-bagtest bagtest-ar.cc
ll-bagtest: ll-bag.h bagtest-ll.cc
	g++ -std=c++11 -o ll-bagtest bagtest-ll.cc
clean:
	rm ar-bagtest ll-bagtest ar.txt ll.txt
rm:
	rm *~ .*~
