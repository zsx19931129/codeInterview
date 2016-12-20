class Solution {
public:
	void addSequence(vector<vector<int> > &res, vector<int> tmp, int small, int big){
		tmp.clear();
		for(int i=small;i<=big;i++){
			tmp.push_back(i);
		}
		res.push_back(tmp);
	}

    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum < 2){
        	return res;
        }

        int small = 1, big = 2;
        int mid = (sum+1)>>1;		//small能取得最大值
        int curSum = small + big;
        vector<int> tmp;

        while(small < mid){
        	if(curSum == sum){
        		addSequence(res, tmp, small, big);
        	}

        	while(curSum > sum && small < mid){
        		curSum -= small;
        		small++;

        		if(curSum == sum){
        			addSequence(res, tmp, small, big);
        		}
        	}

        	big++;
        	curSum += big;
        }
        return res;
    }
};