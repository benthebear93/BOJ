n = int(input())
x, y = 1, 1
plan = input().split()
dx = [1, -1, 0, 0]
dy = [0 , 0, 1, -1]
movetype = ['R','L','D','U']

for a in plan:
	for i in range(len(movetype)):
		if a == movetype[i]:
			nx = x + dx[i]
			ny = y + dy[i]

		if nx <1 or ny <1 or nx>n or ny>n:
			continue
		x,y = nx, ny
print(x,y)
