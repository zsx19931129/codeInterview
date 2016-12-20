/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:

    ListNode* deleteDuplication(ListNode* pHead)
    {
    	if(!pHead){
    		return NULL;
    	}

    	ListNode* pPreNode = NULL;
    	ListNode* pNode = pHead;
    	while(pNode){
    		ListNode *pNext = pNode->next;

    		bool needDelete = false;

    		if(pNext && pNext->val == pNode->val){
    			needDelete = true;
    		}

    		if(!needDelete){
    			pPreNode = pNode;			//只有不需要删除的时候才更行pPreNode
    			pNode = pNext;
    		}else{
    			int value = pNode->val;
    			ListNode* del = pNode;
    			while( del && del->val == value){
	    			pNext = del->next;

	    			delete del;
	    			del=NULL;

	    			del = pNext;
	    		}

	    		if(!pPreNode){
	    			pHead = pNext;
	    		}else{
	    			pPreNode->next = pNext;
	    		}

	    		pNode = pNext;
    		}
    	}
    	return pHead;
    }
};