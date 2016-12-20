class Solution {
public:
	bool hasPathImpl(char* matrix, int rows, int cols, char* str, int row, int col, int pathLength, bool *visited){
		if(str[pathLength] == '\0'){
			return true;
		}

		bool find = false;
		if( (row >=0 && row < rows) && (col >=0 && col < cols) 
			&& matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col]){
			visited[row * cols + col] = true;

			find = hasPathImpl(matrix, rows, cols, str, row+1, col, pathLength+1, visited)
				|| hasPathImpl(matrix, rows, cols, str, row-1, col, pathLength+1, visited)
				|| hasPathImpl(matrix, rows, cols, str, row, col+1, pathLength+1, visited)
				|| hasPathImpl(matrix, rows, cols, str, row, col-1, pathLength+1, visited);

			if(!find){
				visited[row * cols + col] = false;
			}
		}

		return find;
	}

    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
    	if(matrix == NULL || rows < 1 || cols < 1 || str == NULL){
    		return false;
    	}

    	bool *visited = new bool[rows * cols];
    	memset(visited, 0, rows*cols);

    	int pathLength = 0;
    	for(int row = 0;row < rows;++row){
    		for(int col = 0;col < cols; col++){
    			if(hasPathImpl(matrix, rows, cols, str, row, col, pathLength, visited)){
    				return true;
    			}
    		}
    	}

    	delete[] visited;
    	return false;
    }
};