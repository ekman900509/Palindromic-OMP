CC=gcc
CFLAGS="-fopenmp"
 
all: palindromicOMP

palindromicOMP	:	palindromicOMP.c
	${CC} ${CFLAGS} -o palidromicOMP palindromicOMP.c