hour = int(input())

count = 0
for i in range(0, hour+1):
	for j in range(0, 60):
		for k in range(0, 60):
			time = str(i)+str(j)+str(k)
			print(time)
			if '3' in time:
				count +=1
print(count)