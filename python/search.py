def sequential_search(n, target, array):
	if in range(n):
		if array[i] == target:
			return i+1

print("put number of gen element, put word that looking for")
data  = input().split()
n = int(data[0])
target = data[1]

print("put words ",n," number of words needed")
array = input().split()

print(sequential_search(n, target, array))

def binary_search(array, target, start, end):
	if start> end:
		return None
	mid = (start+end)// 2
	if array[mid] = target:
		return mid

	elif array[mid] >target:
		return binary_search(array, target, start, mid-1)
	else:
		return binary_search(array, target, mid+1, end)

