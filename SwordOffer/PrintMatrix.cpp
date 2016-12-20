class Solution {
public:

	void printMatrixInCircle(const vector<vector<int> > &matrix, int start, int columns, int rows, vector<int> &res){
		int endX = columns - 1 - start;
		int endY = rows - 1 - start;

		//一行
		for(int i=start;i<=endX;i++){
			res.push_back(matrix[start][i]);
		}
		//一列
		if(endY-start>0){
			for(int i=start+1;i<=endY;i++){
				res.push_back(matrix[i][endX]);
			}
		}

		//二行
		if( (endX-start>0) && (endY-start>0) ){
			for(int i=endX-1;i>=start;i--){
				res.push_back(matrix[endY][i]);
			}
		}

		//二列
		if( (endX-start>0) && (endY-start>1) ){
			for(int i=endY-1;i>=start+1;i--){
				res.push_back(matrix[i][start]);
			}
		}
	}

    vector<int> printMatrix(vector<vector<int> > matrix) {
    	vector<int> res;
    	if(matrix.size() == 0 || matrix[0].size() == 0){
    		return res;
    	}

    	int rows = matrix.size();
    	int columns = matrix[0].size();

    	int start=0;

    	//判断是否能够继续打印
    	while(rows > 2*start && columns > 2*start){
    		printMatrixInCircle(matrix, start, columns, rows, res);
    		start++;
    	}

    	return res;
    }
};