curr_pos = input() # 'a1'
row = int(curr_pos[1]) # - #
column = int(ord(curr_pos[0]))-int(ord('a')) + 1

# print(curr_pos)
# print(curr_pos[0])
print("raw : ", int(curr_pos[1]))
print("col : ", int(ord(curr_pos[0]))-int(ord('a')) + 1)
#left, right | up and down 
move = [(-2, -1), (-2, 1), (2, -1), (2, 1),(2, -1), (-1, -2), (1,-2), (-1, 2), (1, 2)]

result = 0 
for step in move:
	next_row = row + step[0]
	next_col = column + step[1]
	if next_row >=1 and next_row <=8 and next_col>=1 and next_col < 8:
		result+=1
print(result)