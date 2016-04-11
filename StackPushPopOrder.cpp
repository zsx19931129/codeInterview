#include <stack>

using namespace std;

class Solution {
    public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    	bool valid = false;

    	int pushLength = pushV.size();
    	int popLength = popV.size();

    	if(pushLength != 0 && popLength != 0 && pushLength == popLength){
    		int pNextPush = 0;
    		int pNextPop = 0;

    		stack<int> data;

    		while(pNextPop<popLength){
    			while(data.empty() || (data.top() != popV[pNextPop]) ){
    				if(pNextPush == pushLength){
    					break;
    				}

    				data.push(pushV[pNextPush]);
    				pNextPush++;
    			}

    			if(data.top() != popV[pNextPop]){
    				break;
    			}

    			data.pop();
    			pNextPop++;
    		}

    		if(data.empty() && pNextPop == popLength){
    			valid = true;
    		}
    	}

    	return valid;
    }
};