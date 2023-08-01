//
// Created by Administrator on 2023-08-01(001).
//

#ifndef QUEUE_QUEUEARRAY_H
#define QUEUE_QUEUEARRAY_H

#define INIT_CAPACITY 100

typedef int Item;
typedef struct queue_type *Queue;

void terminate(const char *msg);
int get_size(Queue q);
Queue create();
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void reallocate(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);

#endif //QUEUE_QUEUEARRAY_H
