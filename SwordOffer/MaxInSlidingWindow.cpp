#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
    	vector<int> res;
        int vsize = num.size();
        if(size < 1 || vsize < size){
        	return res;
        }

        //存储当前队列在原向量中的下标
        deque<int> index;
        for(int i=0;i<size;i++){
        	while(!index.empty() && num[index.back()] < num[i] ){
        		index.pop_back();
        	}
        	index.push_back(i);
        }

        res.push_back(num[index.front()]);

        for(int i=size;i<vsize;i++){
        	while(!index.empty() && num[index.back()] < num[i] ){
        		index.pop_back();
        	}

        	if(!index.empty() && index.front() <= i-size){
        		index.pop_front();
        	}

        	index.push_back(i);
        	res.push_back(num[index.front()]);
        }

        return res;
    }
};