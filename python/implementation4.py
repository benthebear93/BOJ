n, m = map(int, input().split()) # n <=3. m <=50
d = [[0]*m for _ in range(n)]

x, y, views = map(int, input().split()) #view : 0 = north, 1 = east, 2 = south, 3 = west
array =[]
for i in range(n):
	array.append(list(map(int, input().split())))

dx = [-1, 0, 1,  0]
dy = [ 0, 1, 0, -1]

def turn_left():
	global views
	views = views -1
	if views == -1:
		views = 3

d[x][y] = 1 #save current position
count = 1
turn_check = 0
while True:
	turn_left()
	nx = x + dx[views]
	ny = y + dy[views]
	if d[nx][ny]==0 and array[nx][ny]==0:
		d[nx][ny]=1
		x = nx
		y = ny
		count+=1
		turn_check = 0
		continue
	else:
		turn_check +=1
	if turn_check == 4:
		nx = x - dx[views]
		ny = y - dy[views]
		if array[nx][ny] == 0:
			x = nx
			y = ny
		else:
			break
		turn_check = 0

print(count)




