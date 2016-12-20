//两个栈，一个负责进栈，一个负责出栈，当出栈时，如果出栈栈空，出进栈所有元素入出栈

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
        	while(!stack1.empty()){
        		stack2.push(stack1.top());
        		stack1.pop();
        	}
        }
        if(stack2.empty()){
        	//出错
        	return -1;
        }else{
        	int ret = stack2.top();
        	stack2.pop();
        	return ret;
        }
    }

private:
    stack<int> stack1;			//进元素栈
    stack<int> stack2;			//出元素栈
};