n, k = map(int, input().split())
result  = 0

# while n >= k:
# 	if n%k ==0:
# 		n = n/k
# 		result +=1
# 	else:
# 		n-=1
# 		result +=1
# while n >1:
# 	n-=1
# 	result +=1

# print(result)

while True:
	target = (n//k)*k
	print(target) #24 , 6 , 0
	result += (n-target)
	#print(result) #1 4 7
	n = target
	#print(n)
	if n < k:
		break
	result +=1 #2 5 8
	n//=k # n = 8 
result+=(n-1)
print("ans:", result)
