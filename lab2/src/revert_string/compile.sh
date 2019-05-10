gcc -c swap.c -o swap.o
gcc -c -fPIC revert_string.c -o revert_string.o
gcc -shared revert_string.o swap.o -o libDynamic.so
ar rcs libStatic.a swap.o revert_string.o
gcc main.c -L$(pwd) -lStatic -o RevStrSTAT
gcc main.c -L$(pwd) -lDynamic -o RevStrDYN
gcc tests.c -L$(pwd) -lDynamic -o revertTests -lcunit
./revertTests