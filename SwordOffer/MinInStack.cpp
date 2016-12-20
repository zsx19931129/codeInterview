#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:
	stack<int> valStack;
	stack<int> auxStack;		//辅助栈存储当前的最小值
    void push(int value) {
        if(auxStack.empty() || value < auxStack.top()){
        	auxStack.push(value);
        }else{
        	auxStack.push(auxStack.top());
        }
        valStack.push(value);
    }
    void pop() {
        assert( !valStack.empty() && !auxStack.empty());

        valStack.pop();
        auxStack.pop();
    }
    int top() {
        assert( !valStack.empty() && !auxStack.empty() );

        return valStack.top();
    }
    int min() {
        assert( !valStack.empty() && !auxStack.empty() );

        return auxStack.top();
    }
};