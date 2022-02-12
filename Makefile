testlib: test.cpp
	mkdir -p build
	g++ -o build/test common.cpp logging.cpp test.cpp -Wall -Werror -std=c++2a
runtestlib: testlib
	./build/test
