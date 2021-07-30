def binary_search(array, target, start, end):
	while start <=end:
		mid = (start+end)//2
		if array[mid] ==target:
			return mid
		elif array[mid]>target:
			end = mid-1
			#binary_search(array, target, start, end-1):
		else:
			start = mid+1
	return None

n = int(input())
product = list(map(int, input().split()))
m = int(input())
find_product = list(map(int, input().split()))

product.sort()

for i in find_product:
	result = binary_search(product,i, 0, n-1)
	if result!=None:
		print('yes', end=' ')
	else:
		print('no', end=' ')