CC 	= g++-4.9 -std=c++14
CXXFLAG	= -O0 -Wall -Wextra -W -ggdb3 -I. -pthread -L.
UNITTEST_LIB = -lgtest-ia32

test: test.o
	$(CC) $^ -o $@ $(CXXFLAG) $(UNITTEST_LIB)

test.o: test.cpp RbBST.hpp
	$(CC) $< -c $(CXXFLAG)
	
clean:
	rm -f *.o test

rebuild:	clean test

.PHONY:	clean rebuild test
