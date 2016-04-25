CC 			= g++-4.9 -std=c++14
CXXFLAG 	= -O0 -Wall -Wextra -W -ggdb3 -pthread -I.
UNITTEST	= gtest-ia32.a

test 		: test.o $(UNITTEST)
	$(CC) $^ -o $@ $(CXXFLAG)

test.o 		: test.cpp RbBST.hpp
	$(CC) $< -c $(CXXFLAG)
	
clean		:
	rm -f *.o test

rebuild		:	clean test

.PHONY		:	clean rebuild
