n = int(input())
array = list(map(int, input().split()))

d = [0]*7
d[0] = array[0]
d[1] = max(array[0], array[1])

for i in range(2, n):
	print("d : ", d)
	print("d[",i-1,"] :",d[i-1])
	print("d[",i-2,"] :",d[i-2]," array[", i, "]", array[i])
	print(d[i-2]+array[i])
	d[i] = max(d[i-1], d[i-2]+array[i]) # 1 3 6  -> 3 or 1+6 ?


print(d[n-1])