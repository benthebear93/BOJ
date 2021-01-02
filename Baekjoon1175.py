import numpy as np
from collections import deque
M, N = map(int, input().split())  # map input #n row, m column
map = []
visited = []
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
temp_x = 0
temp_y = 0
st_pos = [0 , 0]
c_pos = [0, 0]
if N > 50 and M > 50:
    print("M , N has to be smaller & equal then 50")
else:
    for a in (0, N):
        map.append(list(input()))

for i in (0, N):
    for j in (0, M):
        if map[i][j] == 'S':
            st_pos[0] = i
            st_pos[1] = j
        elif map[i][j] == 'C':
            c_pos[0] = i
            c_pos[1] = j

def bfs():
    queue = deque()
    queue.append(0, 0)
    while(queue):
        (x, y) = queue.popleft()
        temp = (x, y)
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]

            #can't not go out the class
            if nx < 0 or nx > M or ny <0 or ny >N:
                continue

            #wall check
            if map[nx][ny] =='#':
                continue
            # change direction
            if map[nx][ny] == '.':
                map[nx][ny] = map[x][y] + 1
                queue.append((nx, ny))

            if map[nx][ny] == 'C':
                map[nx][ny] = map[x][y] + 1
                distance +=1

            if map[nx][ny] ==
            temp_x = dx[i]
            temp_y = dy[i]