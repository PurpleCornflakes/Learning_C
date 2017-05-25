### Compile main.c,hello.c and hello.h

- Method 1: directly compile them simultaneously

`gcc main.c hello.c -o main`

- Method2: compile hello.c to hello.o file, which is an object file, being the middle file

`gcc -c hello.c`  the output name is hello.o by default 
`gcc main.c hello.o -o main` 

here the hello.o containing the same information as in hello.c, but compiled.

- Method3: futhermore generate libmyhello.a from hello.o

`ar -cr libmyhello.a hello.o`  
.a is static lib file

then link the static lib to main program

`gcc main.c -L. -lmyhello -o main`

or

`gcc main.c libmyhello.a -o main`

once compiled this way, the static lib file is unnecessary for the main program.

- Mehthod 4: using dynamic lib file .so

`gcc -shared -fPIC -o libmyhello.so hello.o`
-fPIC: Position Independent Code

then link .so file to main.c

`gcc main.c -L. -lmyhello -o main`

or 

`gcc main.c libmyhello.so -o main`

once compiled this way, the dynamic lib file is necessary for the main program.
every time main program is executed, it searches the dynamic lib and call the code in it.

when a static lib and a dynamic lib coexist and have a common name, gcc priorly links the dynamic one.
