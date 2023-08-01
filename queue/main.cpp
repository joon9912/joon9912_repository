#include <stdio.h>
#include "queueADT.h"
#include "queueADT.cpp"
// #include "queueArray.h"

int main() {
    Queue queue = create();
    Position cur;
    cur.x = 0;
    cur.y = 0;

    enqueue(queue, cur);

    maze[0][0] = -1;
    bool found = false;

    while (!is_empty(queue)) {
        Position cur = dequeue(queue);
        for (int dir = 0; dir < 4; ++dir) {
            if (movable(cur, dir)) {
                Position p = move_to(cur, dir);
                maze[p.x][p.y] = maze[cur.x][cur.y] - 1;
                if (p.x == MAZE_SIZE - 1 && p.y == MAZE_SIZE - 1) {
                    printf("Found the path.\n");
                    found = true;
                    break;
                }
                enqueue(queue, p);
            }
        }
    }

    for (int i = 0; i < MAZE_SIZE; ++i) {
        for (int j = 0; j < MAZE_SIZE; ++j)
            printf("%4d ", maze[i][j]);
        printf("\n");
    }

    print_maze();

    destroy(queue);

    return 0;
}