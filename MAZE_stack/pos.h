//
// Created by Administrator on 2023-07-26(026).
//

#ifndef MAZE_STACK_POS_H
#define MAZE_STACK_POS_H

typedef struct pos {
    int x, y;
} Position;

Position move_to(Position pos, int dir) {
    int dx[] {-1,0,1,0 };
    int dy[] { 0,1,0,-1 };
    Position next;
    next.x = pos.x + dx[dir];
    next.y = pos.y + dy[dir];

    return next;
}

#endif // MAZE_STACK_POS_H