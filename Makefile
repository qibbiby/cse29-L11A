restr: restr.c
	gcc -Wall -Wno-unused-variable -fsanitize=address -g restr.c -o restr

jstr.asan: jstr.c
	gcc -Wall -Wno-unused-variable -fsanitize=address -g jstr.c -o jstr

jstr: jstr.c
	gcc -Wall -Wno-unused-variable -g jstr.c -o jstr
