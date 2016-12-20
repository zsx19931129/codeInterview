#include <cstring>

using namespace std;

class Solution {
public:
	int getSum(int num){
		int ret = 0;
		while(num){
			ret += num%10;
			num = num/10;
		}
		return ret;
	}

	bool check(int threshold, int rows, int cols, int curx, int cury, bool *visited){
		if( (curx >= 0 && curx < rows) && (cury >= 0 && cury < cols) && !visited[curx*cols + cury] && (getSum(curx) + getSum(cury) <= threshold ) ){
			return true;
		}else{
			return false;
		}
	}
	int movingCountImpl(int threshold, int rows, int cols, int curx, int cury, bool *visited){
		int count = 0;

		if(check(threshold, rows, cols, curx, cury, visited)){
			count++;
			visited[curx * cols + cury] = true;
			count += movingCountImpl(threshold, rows, cols, curx-1, cury, visited);
			count += movingCountImpl(threshold, rows, cols, curx+1, cury, visited);
			count += movingCountImpl(threshold, rows, cols, curx, cury-1, visited);
			count += movingCountImpl(threshold, rows, cols, curx, cury+1, visited);
		}

		return count;
	}

    int movingCount(int threshold, int rows, int cols)
    {
        bool *visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);

        int count = movingCountImpl(threshold, rows, cols, 0, 0, visited);

        delete[] visited;
        return count;
    }
};