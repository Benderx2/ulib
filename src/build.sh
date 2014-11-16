export CFLAGS="-g -std=gnu99 -I ./include/"
gcc $CFLAGS -c ustack.c -o ustack.o 
gcc $CFLAGS -c ubuffer.c -o ubuffer.o
gcc $CFLAGS -c umesh.c -o umesh.o
gcc $CFLAGS -c umatrix.c -o umatrix.o
gcc $CFLAGS -c umain.c -o umain.o
ar rcs ulib.a ubuffer.o ustack.o umesh.o umain.o umatrix.o
gcc $CFLAGS test.c ulib.a -o testulib
mv ./testulib ../bin/
mv ./ulib.a ../bin/lib/
rm ubuffer.o ustack.o umesh.o umatrix.o umain.o
