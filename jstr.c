#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct String {
    uint64_t length;    // should always equal strlen(contents)
    char* contents;     // should always have allocated space of length + 1, including null terminator
};

typedef struct String String;

String new_String(char* init_contents) {
    uint64_t size = strlen(init_contents);
    char* contents = calloc(size, sizeof(char));
    strcpy(contents, init_contents);
    String r = { size, contents };
    return r;
}

String plus(String s1, String s2) {
    uint64_t new_size = s1.length + s2.length + 1;
    char* new_contents = calloc(new_size, sizeof(char));
    strncpy(new_contents, s1.contents, s1.length);
    strncpy(new_contents + s1.length, s2.contents, s2.length);
    new_contents[new_size - 1] = 0;
    String r = { new_size, new_contents };
    return r;
}


int main() {
    String s = new_String("str");
    printf("%s\n", s.contents);

    String s2 = new_String("another");

    String s3 = plus(s, s2);
    printf("%s\n", s3.contents);
}