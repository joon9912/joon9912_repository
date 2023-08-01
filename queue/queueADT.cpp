//
// Created by Administrator on 2023-08-01(001).
//
#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *front;
    struct node *rear;
    int size;
};

void terminate(const char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

int get_size(Queue q) {
    return q->size;
}

Queue create() {
    Queue q = (Queue)malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.");
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void destroy(Queue q) {
    make_empty(q);
    free(q);
}

void make_empty(Queue q) {
    while (!is_empty(q))
        dequeue(q);
    q->size = 0;
}

bool is_empty(Queue q) {
    return q->front == NULL;
}

void enqueue(Queue q, Item i) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: queue is full.");

    new_node->data = i;
    new_node->next = NULL;
    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

Item dequeue(Queue q) {
    struct node *old_front;
    Item i;

    if (is_empty(q))
        terminate("Error in dequeue: queue is empty.");

    old_front = q->front;
    i = old_front->data;
    q->front = old_front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(old_front);
    q->size--;
    return i;
}

Item peek(Queue q) {
    if (is_empty(q))
        terminate("Error in peek: queue is empty.");
    return q->front->data;
}

int dx[]{-1,0,1,0};
int dy[]{0,1,0,-1};

bool movable(Position pos, int dir) {
    int nx = pos.x + dx[dir];
    int ny = pos.y + dy[dir];

    if (maze[nx][ny] == 0 && nx >= 0 && ny >= 0 && nx < MAZE_SIZE && ny < MAZE_SIZE)
        return true;
    else
        return false;
}

Position move_to(Position pos, int dir) {
    Position p;

    p.x = pos.x + dx[dir];
    p.y = pos.y + dy[dir];

    return p;
}

void print_maze() {
    int nx, ny;
    nx = ny = MAZE_SIZE - 1;

    if (maze[nx][ny] >= 0) return;
    while (1) {
        printf("(%d, %d)\n", nx, ny);

        for (int i = 0; i <= 3; ++i) {
            if (maze[nx + dx[i]][ny + dy[i]] == maze[nx][ny] + 1) {
                nx = nx + dx[i];
                ny = ny + dy[i];
                break;
            }
        }

        if (nx == 0 && ny == 0) {
            printf("(%d, %d)\n", nx, ny);
            break;
        }
    }
}