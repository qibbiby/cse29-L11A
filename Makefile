restr: restr.c
	gcc -Wall -Wno-unused-variable -fsanitize=address -g restr.c -o restr
