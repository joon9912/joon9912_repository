#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

char *names[CAPACITY];
char *numbers[CAPACITY];
int n = 0; // # of people in phone directory

void add();
void find();
void status();
void remove();
void load();
void save();

int main() {
    char command[BUFFER_SIZE];
    while (1) {
        printf("$ ");
        scanf("%s", command);

        if (strcmp(command, "read") == 0)
            load();
        else if (strcmp(command, "save") == 0)
            save();
        else if (strcmp(command, "add") == 0)
            add();
        else if (strcmp(command, "find") == 0)
            find();
        else if (strcmp(command, "delete") == 0)
            remove();
        else if (strcmp(command, "status") == 0)
            status();
        else if (strcmp(command, "exit") == 0)
            break;
    }
    return 0;
}

int search(char *name) {
    int i;
    for (i = 0; i < n; ++i) {
        if (strcmp(names[i], name) == 0)
            return i;
    }
    return -1;
}

void add() {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];

    scanf("%s", buf1);
    scanf("%s", buf2);

    int i = n - 1;
    while (i >= 0 && strcmp(names[i], buf1) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[n] = strdup(buf1);
    numbers[n++] = strdup(buf2);

    printf("%s was added successfully.\n", buf1);
}

void find() {
    char buf[BUFFER_SIZE];
    scanf("%s", buf);

    int index = search(buf);
    if (index == -1)
        printf("No person named '%s' exists.\n", buf);
    else
        printf("%s\n", numbers[index]);
}

void status() {
    int i;
    for (i = 0; i < n; ++i)
        printf("%s  %s\n", names[i], numbers[i]);
    printf("Total %d persons.\n", n);
}



void remove() {
    char buf[BUFFER_SIZE];
    scanf("%s", buf);

    int index = search(buf);
    if (index == -1) {
        printf("No person named '%s' exists.\n", buf);
        return;
    }

    int j = index;
    for (; j < n - 1; ++j) {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }

    n--;
    printf("'%s' was deleted successfully. \n", buf);
}

void load() {
    char fileName[BUFFER_SIZE];
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }

    while ((fscanf(fp, "%s", buf1) != EOF)) {
        fscanf(fp, "%s", buf2);
        names[n] = strdup(buf1);
        numbers[n] = strdup(buf2);
        n++;
    }
    fclose(fp);
}

void save() {
    int i;
    char fileName[BUFFER_SIZE];
    char tmp[BUFFER_SIZE];

    scanf("%s", tmp);
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }

    for (i = 0; i < n; ++i) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}