array = [7,5,9,0,3,1,6,2,4,8]

def selection_sort(array):
	for i in range(len(array)):
		min_index = i
		for j in range(i+1, len(array)):
			if array[min_index]>array[j]:
				min_index=j
				
		# swap code #
		array[i], array[min_index] = array[min_index], array[i]  
	print(array)

def insertion_sort(array):
	for i in rnage(1, len(array)):
		if array[j] < array[j-1]:
			array[j], array[j-1] = array[j-1], array[j]
		else:
			break
	print(array)

def quick_sort(array, start, end):
	if start >= end:
		return

	pivot = start
	left = start+1
	right = end
	while left<=right:
		#find element bigger than pivot
		while left <= end and array[left]<=array[pivot]:
			left+=1
		while right > start and array[right] >= array[pivot]:
			right-=1
		if left > right:
			array[right], array[pivot] = array[pivot] , array[right]
		else:
			array[left], array[pivot] = array[pivot] , array[left]
	quick_sort(array, start, right-1)
	quick_sort(array, right+1, end)
quick_sort(array, 0,  len(array)-1)
print(array)


def quick_sort_simple(array):
	 if len(array)<=1:
	 	return array

	 pivot=array[0]
	 tail =array[1:]

	 left_side = [x for in tail if x <=pivot]
	 right_side = [x for x in tail if x>pivot]

	 return quick_sort_simple(left_side) +[pivot]  + quick_sort(right_side)

print(quick_sort_simple(array))

def count_sort(array):
	cout = [0] *(max(array)+1)
	
	for i in range(len(array)):
		count[array[i]] +=1

	for i in range(len(count)):
		for j in range(coutn[i]):
			print(i, end=' ')
			