/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

#include <stack>

using namespace std;

class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> res;

        if(head == NULL){
        	return res;
        }

        stack<ListNode*> stk;
        ListNode *tmp = head;
        while(tmp){
        	stk.push(tmp);
        	tmp = tmp->next;
        }

        while(!stk.empty()){
        	tmp = stk.top();
        	res.push_back(tmp->val);
        	stk.pop();
        }
        return res;
    }
};