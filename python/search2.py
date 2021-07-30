n, m = list(map(int, input().split()))
ddok_len = list(map(int, input().split()))

ddok_len.sort()

start = 0
end = max(ddok_len)
result = 0
while(start<=end):
	for i in ddok_len:
		total= 0
		mid = (start+end)//2
		for x in ddok_len:
			if x > mid:
				total += x-mid
		if total< m:
			end = mid-1
		else:
			start = mid+1
			result = mid

print(result)
