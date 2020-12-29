import numpy as np
from collections import deque
M, N = map(int, input().split())  # map input #n row, m column
map = []
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
temp_x = 0
temp_y = 0
if N > 50 and M > 50:
    print("M , N has to be smaller & equal then 50")
else:
    for a in (0, N):
        map.append(list(input()))

def bfs():
    queue = deque()
    queue.append(0, 0)
    while(queue):
        (x, y) = queue.popleft()

        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if temp_x == dx[i] and temp_y == dy[i]
            #can't not go out the class
            if nx < 0 or nx > M or ny <0 or ny >N:
                continue

            #wall check
            if map[nx][ny] =='#':
                continue
            # change direction
            if map[nx][ny] ==
            temp_x = dx[i]
            temp_y = dy[i]