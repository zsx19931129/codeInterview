# Problem Description: Given a map, mark its nodes as Black or Red, no two adjacent nodes have the same color. Return true or false.

# Python program to find out whether a given graph is Bipartite or not
# It works for disconnected graph also.

# Use matrix to represent graph, V is the num in graph
V = 4

def is_bipartite_util(graph, src, color_array):
	color_array[src] = 1

	# Create a queue (FIFO) of vertex numbers and enqueue
    # source vertex for BFS traversal
    q = [src]
    while q:
    	# Dequeue a vertex from queue
    	u = q.pop(0)
    	
    	# Find all non-colored adjacent vertices
    	for i in range(V):
    		# An edge from u to v exists and destination v is not colored
    		if graph[u][i] and color_array[i] == -1:
    			# Assign alternate color to this adjacent v of u
    			color_array[i] = 1 - color_array[u]
    			q.append(i)
    		else if graph[u][i] and color_array[i] == color_array[u]:
    			return False
    return True

def is_bipartite(graph):
	# Create a color array to store colors assigned to all veritces. Vertex/ number is used as index in this
    # array. The value '-1' of  color_array[i] is used to indicate that no color is assigned to vertex 'i'.
    # The value 1 is used to indicate first color is assigned and value 0 indicates second color is assigned.
    color_array = [-1 for i in range(V)]

    for i in range(V):
    	if color_array[i] == -1:
    		if not is_bipartite_util(graph, i, color_array):
    			return False

    return True

# Driver program to test above function
if __name__ == '__main__':
	graph = [
		[0,1,0,1],
		[1,0,1,0],
		[0,1,0,1],
		[1,0,1,0]
	]

	print 'Yes' if is_bipartite(graph) else 'No'
