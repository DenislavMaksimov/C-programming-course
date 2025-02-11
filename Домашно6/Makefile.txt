all: inttypes.out safeadd.out safesubtract.out safemultiply.out safedivide.out

inttypes.out: inttypes.c
	gcc -o inttypes.out inttypes.c

safeadd.out: safeadd.c safeint.c safeint.h
	gcc -o safeadd.out safeadd.c safeint.c

safesubtract.out: safesubtract.c safeint.c safeint.h
	gcc -o safesubtract.out safesubtract.c safeint.c

safemultiply.out: safemultiply.c safeint.c safeint.h
	gcc -o safemultiply.out safemultiply.c safeint.c

safedivide.out: safedivide.c safeint.c safeint.h
	gcc -o safedivide.out safedivide.c safeint.c

clean:
	rm -f *.out
