import numpy as np
from collections import deque
class_map = []
visited = []
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
temp_x = 0
temp_y = 0
st_pos = [0 , 0]
c_pos = [0, 0, 0, 0]



n, m = map(int, input().split())  # map input #n row, m column
line =[]
for i in range(n):
	line.append(list(input()))

def bfs(q, case, visited): #bfs for the distance to C from Robot
	while(q):
		row, col, to = q.popleft()
		if line[row][col] =="C": #arrived to C?
			case.append([visited[row][col][to],row, col, to])
		for k in range(4): #check 4 direction
			if k == to: #pass the same direction
				continue
			temp_x = row + dx[k]
			temp_y = col + dy[k]
			if 0<= temp_x < N and 0 <=temp_y <M and line[temp_x][temp_y] !="#" and visited[temp_x][temp_y][k]==0:
				visited[temp_x][temp_y][k] = visited[row][col][to] + 1
				q.append([temp_x],[temp_y], k)

def dfs(dist, s_r, s_c, to, cnt):
	global ans
	if ans<=dist:
		return 

	if cnt ==2: #delivered both?
		if dist<ans: 
			ans=dist
		return
	visited =[[[0, 0, 0, 0] for j in range(m)] for i in range(n)]
	visited[s_r][s_c][to] = dist
	q = deque([s_r,s_c, to])
	case=[]
	bfs(case,q,visited)

	for n_dist, n_r, n_c, n_to in case:
		L[n_r][n_c]

