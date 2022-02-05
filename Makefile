testlib: test.cpp
	g++ -o test common.cpp logging.cpp test.cpp -Wall -Werror -std=c++2a
runtestlib: testlib
	./test
