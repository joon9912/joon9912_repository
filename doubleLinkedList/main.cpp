#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node* next;
    struct node* prev;
};

typedef struct node Node;

Node *head;
Node *tail;
int size;

void add_ordered_list(char *item);
void add_after(Node *pre, char *item);
void remove_node(char *item);
void print_all();

int main() {
    add_ordered_list("aaa");
    add_ordered_list("bbb");
    add_ordered_list("ccc");

    print_all();

    printf("\n");

    add_ordered_list("ddd");
    remove_node("bbb");

    print_all();

    return 0;
}

void add_after(Node *pre, char *item) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;

    // empty list
    if (pre == NULL && head == NULL) {
        head = new_node;
        tail = new_node;
    }
    else if (pre == NULL) {
        // head != NULL
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else if (pre == tail) {
        // last #
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    else { // in the middle
        new_node->prev = pre;
        new_node->next = pre->next;
        pre->next->prev = new_node;
        pre->next = new_node;
    }
    size++;
}

void add_ordered_list(char *item) {
    Node *p = tail;
    while (p != NULL && strcmp(item, p->data) < 0)
        p = p->prev;
    add_after(p, item);
}

void remove_node(char *item) {
    // if size == 1
    // if p == head
    // if p == tail
    // else

    Node *ptr = head;

    while (ptr != NULL) {
        if (strcmp(ptr->data, item) == 0)
            break;
        ptr = ptr->next;
    }

    if (ptr == NULL) return;

    if (ptr == head) {
        head = ptr->next;
        head->prev = NULL;
    }
    else if (ptr == tail) {
        tail = ptr->prev;
        tail->next = NULL;
    }
    else if (size == 1) {
        head = tail = NULL;
    }
    else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    size--;
}

void print_all() {
    Node *ptr = head;

    while (ptr != NULL) {
        printf("%s\n", ptr->data);
        ptr = ptr->next;
    }
}