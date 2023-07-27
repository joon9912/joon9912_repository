#ifndef MAZE_STACK_STACK_H
#define MAZE_STACK_STACK_H

#include <stdio.h>
#include "pos.h"
#define MAX_STACK_SIZE 100

Position stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty() {
    return top < 0;
}

int isFull() {
    return top >= MAX_STACK_SIZE - 1;
}

void push(Position value) {
    if (!isFull())
        stack[++top] = value;
}

Position pop() {
    if (!isEmpty())
        return stack[top--];
}

#endif //MAZE_STACK_STACK_H
