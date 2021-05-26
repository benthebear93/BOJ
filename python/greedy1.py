n, m, k = map(int, input().split())
# n : number of data 
# m : number of add time
# k : number of overlap
data = list(map(int, input().split()))

data.sort()
first_bignum = data[n-1]
second_bignum = data[n-2]

result  = 0

while True:
	for i in range(k):
		if m == 0:
			break
		result+=first_bignum
		m -=1
	if m ==0:
		break
	result +=second_bignum
	m-=1

print(result)