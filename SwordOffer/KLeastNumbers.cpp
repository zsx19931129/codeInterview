// 用快速排序的划分可以有O(n)解法，二叉树大根堆O(nlogk)的时间复杂度，并可以支持海量数据，因为可以每次只取一部分
// 可以自己实现大根堆，也可以直接用multiset，在stl中，multiset用红黑树（二叉树一种）实现，查找、删除和插入操作都是O(logn)

#include <set>
#include <algorithm>

using namespace std;

typedef multiset<int, greater<int> > inset;
typedef multiset<int, greater<int> >::iterator setIterator;

class Solution {
public:
	bool checkValid(vector<int> &input, int k){
		int vsize = input.size();
		if(k<0 || k>vsize || vsize==0){
			return false;
		}
		return true;
	}

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(!checkValid(input, k)){
        	return res;
        }

        setIterator it;
        inset leastKnums;
        leastKnums.clear();

        for(int i=0;i<input.size();i++){
        	if(leastKnums.size() < k){
        		leastKnums.insert(input[i]);
        	}else{
        		it = leastKnums.begin();
        		if(input[i] < *it){
        			leastKnums.erase(it);
        			leastKnums.insert(input[i]);
        		}
        	}
        }

        for(it = leastKnums.begin();it != leastKnums.end();it++){
        	res.push_back(*it);
        }

        sort(res.begin(), res.end());

        return res;

    }
};