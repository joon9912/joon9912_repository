#include <iostream>
#include <string.h>
#include <ctype.h>

#define STR_SIZE 100

int read_line_comp(char comp[], int limit);
int main() {
    char line[STR_SIZE];
    while (1) {
        printf("$ ");
        int len = read_line_comp(line, STR_SIZE);
        printf("%s:%d\n", line, len);
    }
    return 0;
}

int read_line_comp(char comp[], int limit) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < limit - 1 && (!isspace(ch) || (i > 0 && !isspace(comp[i - 1]))))
            comp[i++] = ch;
    }
    // if last ch is space
    if (i > 0 && isspace(comp[i - 1]))
        i--;
    comp[i] = '\0';

    return i;
}
