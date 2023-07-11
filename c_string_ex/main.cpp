#include <iostream>
#include <string.h>

#define SIZE 100

int read_line(char str[], int limit);
int main() {
    char str[SIZE];

    while (1) {
        printf("$ ");
        // gets(str);
        //
        // fgets(str, SIZE, stdin);
        // str[strlen(str) - 1] = '\0';

        read_line(str, SIZE);
        if (str == "exit") break;

        printf("%s:%d\n", str, strlen(str));
    }

    return 0;
}

int read_line(char str[], int limit) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < limit)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}
