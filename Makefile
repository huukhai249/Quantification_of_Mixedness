
COMPILER      = -g++
OPTIONS       = -pedantic-errors -Wall -Wall -Werror -Wextra -o
LINKER_OPT    = -L/usr/lib -lstdc++ -lm

all: ex2

ex2: ex2.cpp bitmap_image.hpp tinyfiledialogs.c 
	$(COMPILER) $(OPTIONS) ex2 ex2.cpp tinyfiledialogs.c  $(LINKER_OPT)

valgrind_check:
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes -v ./ex2

clean:
	rm -f core *.o *.bak *stackdump *~

#
# The End !
#
