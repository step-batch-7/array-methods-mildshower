 #! /bin/zsh

rm -rf *.o

if [[ ! -d bin ]]; then
  mkdir bin;
fi

 gcc -c tests/main.c array.c array_void.c
 gcc -o bin/test.out *.o
 rm -rf *.o
 ./bin/test.out