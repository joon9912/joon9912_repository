#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define INIT_CAPACITY 3
// #define BUFFER_SIZE 20
#define CAPACITY 100
#define BUFFER_LENGTH 100

typedef struct person {
    char *name;
    char *number;
    char *email;
    char *group;
} Person;

Person directory[CAPACITY];
char ** names;
char ** numbers;

// int capacity = INIT_CAPACITY;
int n = 0; // # of people in phone directory

char delim[] = " ";

/*
void add();
void find();
void status();
void remove();
void load();
void save();
*/

// void init_directory();
void process_command();

int main() {
    // init_directory();
    process_command();

    return 0;
}

int read_line(FILE *fp, char str[], int limit) {
    int ch, i = 0;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
        if (i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}

void print_person(Person p) {
    printf("%s:\n", p.name);
    printf("    Phone: %s\n", p.number);
    printf("    Email: %s\n", p.email);
    printf("    Group: %s\n", p.group);
}

/*
void init_directory() {
    names = (char **)malloc(INIT_CAPACITY * sizeof(char *));
    numbers = (char **)malloc(INIT_CAPACITY * sizeof(char *));
}
*/

int search(char *name) {
    int i;
    for (i = 0; i < n; ++i) {
        if (strcmp(name, directory[i].name) == 0)
            return i;
    }
    return -1;
}

void add(char *name, char *number, char *email, char *group) {
    int i = n - 1;
    while (i >= 0 && strcmp(directory[i].name, name) > 0) {
        directory[i + 1] = directory[i];
        i--;
    }

    directory[i+1].name = strdup(name);
    directory[i+1].number = strdup(number);
    directory[i+1].email = strdup(email);
    directory[i+1].group = strdup(group);

    n++;
}

int compose_name(char str[], int limit) {
    char *ptr;
    int length = 0;

    ptr = strtok(NULL, delim);
    if (ptr == NULL)
        return 0;

    strcpy(str, ptr);
    length += strlen(ptr);

    while ((ptr = strtok(NULL, " ")) != NULL) {
        if (length + strlen(ptr) + 1 < limit) {
            str[length++] = ' ';
            str[length] = '\0';
            strcat(str, ptr);
            length += strlen(ptr);
        }
    }
    return length;
}

void handle_add(char *name) {
    char number[BUFFER_LENGTH], email[BUFFER_LENGTH], group[BUFFER_LENGTH];
    char empty[] = " ";

    printf("    Phone: ");
    read_line(stdin, number, BUFFER_LENGTH);

    printf("    Email: ");
    read_line(stdin, email, BUFFER_LENGTH);

    printf("    Group: ");
    read_line(stdin, group, BUFFER_LENGTH);

    add(name, (char *)(strlen(number) > 0 ? number : empty),
                (char *)(strlen(email) > 0 ? email : empty),
                (char *)(strlen(group) > 0 ? group : empty));

    printf("%s was added successfully.\n", name);
}

void find(char *name) {
    int index = search(name);
    if (index == -1)
        printf("No person named '%s' exists.\n", name);
    else
        print_person(directory[index]);
}

void status() {
    int i;
    for (i = 0; i < n; ++i)
        print_person(directory[i]);
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
        directory[j] = directory[j + 1];
    }
    n--;
    printf("'%s' was deleted successfully. \n", name);
}

void load(char* fileName) {
    char buffer[BUFFER_LENGTH];
    char *name, *number, *email, *group;

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }

    while (1) {
        if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)
            break;
        name = strtok(buffer, "#");
        number = strtok(NULL, "#");
        email = strtok(NULL, "#");
        group = strtok(NULL, "#");
        add(name, number, email, group);
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
        fprintf(fp, "%s#", directory[i].name);
        fprintf(fp, "%s#", directory[i].number);
        fprintf(fp, "%s#", directory[i].email);
        fprintf(fp, "%s#\n", directory[i].group);
    }
    fclose(fp);
}

void process_command() {
    char command_line[BUFFER_LENGTH];
    char *command, *argument;
    char name_str[BUFFER_LENGTH];

    while (1) {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
            continue;

        command = strtok(command_line, delim);
        if (command == NULL) continue;

        if (strcmp(command, "read") == 0) {
            argument = strtok(NULL, delim);

            if (argument == NULL) {
                printf("File name required.\n");
                continue;
            }
            load(argument);
        }
        else if (strcmp(command, "save") == 0) {
            argument = strtok(NULL, delim);

            if (argument == NULL || strcmp(argument, "as") != 0) {
                printf("Invalid arguments.\n");
                continue;
            }
            argument = strtok(NULL, delim);
            if (argument == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            save(argument);
        }
        else if (strcmp(command, "add") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Name required.\n");
                continue;
            }

            handle_add(name_str);
         }
        else if (strcmp(command, "find") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Name required.\n");
                continue;
            }

            find(name_str);
        }
        else if (strcmp(command, "delete") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Invalid arguments.\n");
                continue;
            }
            remove(name_str);
        }
        else if (strcmp(command, "status") == 0)
            status();
        else if (strcmp(command, "exit") == 0)
            break;
    }
}