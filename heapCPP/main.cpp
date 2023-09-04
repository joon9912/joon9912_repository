#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 256
#define ARR_SIZE 10

// MAX Heap
// data > 0
// data = 0 == empty
// index >= 1

int heap[HEAP_SIZE];
int heap_count; // heap의 원소 개수 및 마지막 data 가리킴

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void init() { heap_count = 0; }

int size() { return heap_count; }

void push(int data) {
    heap[++heap_count] = data;

    int child = heap_count;
    int parent = child / 2;
    while (child > 1 && heap[parent] < heap[child]) {
        swap(&heap[parent], &heap[child]);
        child = parent;
        parent = child / 2;
    }
}

int pop() {
    int result = heap[1];

    swap(&heap[1], &heap[heap_count]);
    heap_count--;

    int parent = 1;
    int child = parent * 2;
    if (child + 1 <= heap_count) {
        child = (heap[child] > heap[child + 1]) ? child : child + 1;
    }

    while (child <= heap_count && heap[parent] < heap[child]) {
        swap(&heap[parent], &heap[child]);

        parent = child;
        child = child * 2;
        if (child + 1 <= heap_count) {
            child = (heap[child] > heap[child + 1]) ? child : child + 1;
        }
    }

    return result;
}

int main() {
    int arr[ARR_SIZE];

    srand((unsigned)time(NULL));

    for (int i = 0; i < ARR_SIZE; ++i) {
        arr[i] = rand() % 50 + 1; // 1 ~ 50
    }

    init();
    for (int i = 0; i < ARR_SIZE; ++i) {
        push(arr[i]);
    }

    for (int i = 0; i < ARR_SIZE; ++i) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}
