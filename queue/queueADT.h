//
// Created by Administrator on 2023-08-01(001).
//

#ifndef QUEUE_QUEUEADT_H
#define QUEUE_QUEUEADT_H

#define MAZE_SIZE 7

typedef struct pos {
    int x;
    int y;
} Position;
typedef Position Item;
typedef struct queue_type *Queue;
int maze[MAZE_SIZE][MAZE_SIZE] {
    0,0,0,0,1,0,0,
    0,1,1,0,1,0,1,
    0,0,1,0,0,0,0,
    1,0,1,1,1,1,1,
    0,0,0,0,1,0,0,
    1,0,1,1,1,1,0,
    0,0,0,0,0,0,0,
};

Queue create();
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
int get_size(Queue q);
bool movable(Position pos, int dir);
Position move_to(Position pos, int dir);
void print_maze();

#endif //QUEUE_QUEUEADT_H
