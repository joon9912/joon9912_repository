#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAPACITY 3
#define BUFFER_SIZE 20

char ** names;
char ** numbers;

int capacity = INIT_CAPACITY;
int n = 0; // # of people in phone directory

char delim[] = " ";

void add();
void find();
void status();
void remove();
void load();
void save();

void init_directory();
void process_command();

int main() {
    init_directory();
    process_command();

    return 0;
}

int read_line(char str[], int limit) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';

    return i;
}

void init_directory() {
    names = (char **)malloc(INIT_CAPACITY * sizeof(char *));
    numbers = (char **)malloc(INIT_CAPACITY * sizeof(char *));
}

int search(char *name) {
    int i;
    for (i = 0; i < n; ++i) {
        if (strcmp(names[i], name) == 0)
            return i;
    }
    return -1;
}

void reallocate() {
    int i;

    capacity *= 2;
    char **tmp1 = (char **)malloc(capacity * sizeof(char *));
    char ** tmp2 = (char **)malloc(capacity * sizeof(char *));

    for (int i = 0; i < n; ++i) {
        tmp1[i] = names[i];
        tmp2[i] = numbers[i];
    }

    free(names);
    free(numbers);

    names = tmp1;
    numbers = tmp2;
}

void add(char *name, char *number) {
    if (n >= capacity)
        reallocate();

    int i = n - 1;
    while (i >= 0 && strcmp(names[i], name) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[n] = strdup(name);
    numbers[n++] = strdup(number);
}

void find(char *name) {
    int index = search(name);
    if (index == -1)
        printf("No person named '%s' exists.\n", name);
    else
        printf("%s\n", numbers[index]);
}

void status() {
    int i;
    for (i = 0; i < n; ++i)
        printf("%s  %s\n", names[i], numbers[i]);
    printf("Total %d persons.\n", n);
}

void remove(char* name) {
    int index = search(name);
    if (index == -1) {
        printf("No person named '%s' exists.\n", name);
        return;
    }

    int j = index;
    for (; j < n - 1; ++j) {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }

    n--;
    printf("'%s' was deleted successfully. \n", name);
}

void load(char* fileName) {
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }

    while ((fscanf(fp, "%s", buf1) != EOF)) {
        fscanf(fp, "%s", buf2);
        add(buf1, buf2);
    }
    fclose(fp);
}

void save(char* fileName) {
    int i;

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

void process_command() {
    char command_line[BUFFER_SIZE];
    char *command, *argument1, *argument2;

    while (1) {
        printf("$ ");

        // read all line
        if (read_line(command_line, BUFFER_SIZE) <= 0)
            continue;

        command = strtok(command_line, delim);
        if (command == NULL) continue;

        if (strcmp(command, "read") == 0) {
            argument1 = strtok(NULL, delim);

            if (argument1 == NULL) {
                printf("File name required.\n");
                continue;
            }
            load(argument1);
        }
        else if (strcmp(command, "save") == 0) {
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);

            if (argument1 == NULL || strcmp("as", argument1) != 0
                    || argument2 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            save(argument2);
        }
        else if (strcmp(command, "add") == 0) {
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);

            if (argument1 == NULL || argument2 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            add(argument1, argument2);

            printf("%s was added successfully.\n", argument1);
        }
        else if (strcmp(command, "find") == 0) {
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            find(argument1);
        }
        else if (strcmp(command, "delete") == 0) {
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            remove(argument1);
        }
        else if (strcmp(command, "status") == 0)
            status();
        else if (strcmp(command, "exit") == 0)
            break;
    }
}