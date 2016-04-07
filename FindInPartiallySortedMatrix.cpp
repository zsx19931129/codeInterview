class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        if(array.size() == 0 || array[0].size() == 0){
        	return false;
        }

        int rows = array.size();
        int columns = array[0].size();
        bool find = false;
        int r = 0, c = columns - 1;
        while(r<rows && c>=0){
        	if(array[r][c] == target){
        		find = true;
        		break;
        	}else if(array[r][c] > target){
        		c--;
        	}else{
        		r++;
        	}
        }
        return find;
    }
};