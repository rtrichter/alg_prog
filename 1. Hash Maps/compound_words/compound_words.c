#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NUM_BITS 17

typedef struct word_node {
    char **word;
    struct word_node *next;
} word_node;

int in_hash_table(word_node *hash_table[], char *find, unsigned find_len) {
    unsigned word_code;
    word_node *wordptr;
    word_code = oaat(find, find_len, NUM_BITS);
    wordptr = hash_table[word_code];
    while (wordptr) {
        if((strlen(*(wordptr->word) == find_len)) && (strncmp(*(wordptr->word), find, find_len) == 0)) 
            return 1;
        wordptr = wordptr->next;
    }
    return 0;
}

char *read_line(int size) {
    char *str;
    int ch;
    int len = 0;
    str = malloc(size);
    if (str ==NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
    while ((ch = getchar()) != EOF && (ch != '\n')) {
        str[len++] = ch;
        if (len == size) {
            size *= 2;
            str = realloc(str, size);
            if (str == NULL) {
                fprintf(stderr, "realloc error\n");
                exit(1);
            }
        }
    }
    str[len] = '\O';
    return str;
}

int main() {
    return 0;
}