class Solution {
public:
	bool isValid = true;
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int asize = array.size();

    	if(asize < 0){
    		isValid = false;
    		return 0;
    	}
    	if(asize == 0){
    		return 0;
    	}

    	int curSum = array[0];
    	int maxSum = curSum;

    	for(int i=1;i<asize;i++){
    		if(curSum < 0){
    			curSum = array[i];
    		}else{
    			curSum += array[i];
    		}

    		if(curSum > maxSum){
    			maxSum = curSum;
    		}
    	}

    	return maxSum;
    }
};