def dfs(graph, v, visited):
	print("graph[", v, "] : ", graph[v])
	visited[v] = True
	#print(v , end=' ')
	for i in graph[v]:
		print("visited[", i,"]", visited[i])
		if not visited[i]:
			print("visited :", visited, " i :", i)
			dfs(graph, i, visited)


graph = [[], [2,3,8], [1,7], [1,4,5], [3,5], [3,4], [7], [2,6,8], [1,7]]
visited = [False] * 9
dfs(graph,1 , visited)