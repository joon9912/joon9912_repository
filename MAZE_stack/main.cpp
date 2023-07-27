#include <stdio.h>
#include "pos.h"
#include "stack.h"

#define MAX 100
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

int maze[MAX][MAX];
int n;

void read_maze();
void print_maze();
bool movable(Position pos, int dir);

int main() {
    read_maze();

    // stack s;
    Position cur;
    cur.x = cur.y = 0;

    while(1) {
        maze[cur.x][cur.y] = VISITED;
        if (cur.x == n-1 && cur.y == n-1) {
            printf("Found the path.\n");
            break;
        }
        bool forwarded = false;
        for (int dir = 0; dir < 4; ++dir) { // 0:N, 1:E, 2:S, 3:W
            if (movable(cur, dir)) {
                push(cur);
                cur = move_to(cur, dir);
                forwarded = true;
                break;
            }
        }
        if (!forwarded) {
            maze[cur.x][cur.y] = BACKTRACKED;
            if (isEmpty()) {
                printf("No path exists.\n");
                break;
            }
            cur = pop();
        }
    }

    print_maze();

    return 0;
}

bool movable(Position pos, int dir) {
    int dx[] {-1,0,1,0 };
    int dy[] { 0,1,0,-1 };

    int nx = pos.x + dx[dir];
    int ny = pos.y + dy[dir];

    if (maze[nx][ny] == PATH
           && nx >= 0 && nx < n && ny >= 0 && ny < n)
    {
        return true;
    }
    return false;
}

void print_maze() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
}

void read_maze() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &maze[i][j]);
    }
}