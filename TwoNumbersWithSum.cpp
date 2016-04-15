class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int vsize = array.size();
        vector<int> res;
        int front = 0, back = vsize-1;
        while(front < back){
        	int curSum = array[front] + array[back];
        	if(curSum == sum){
        		res.push_back(array[front]);
        		res.push_back(array[back]);
        		return res;
        	}else if(curSum < sum){
        		front++;
        	}else{
        		back--;
        	}
        }
        return res;
    }
};