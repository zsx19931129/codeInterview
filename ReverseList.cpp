/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    // ListNode* ReverseList(ListNode* pHead) {
    // 	ListNode *reverseHead = NULL;
    // 	ListNode *pNode = pHead;
    // 	ListNode *pPrev = NULL;
    // 	while(pNode){
    // 		ListNode *pNext = pNode->next;
    // 		if(!pNext){
    // 			reverseHead = pNode;
    // 		}

    // 		pNode->next = pPrev;
    		
    // 		pPrev = pNode;
    // 		pNode = pNext;
    // 	}

    // 	return reverseHead;
    // }

    //递归反转链表
    ListNode* ReverseList(ListNode* pHead){
    	ListNode *reverseHead = NULL;

    	if(pHead){
    		ListNode* pNext = pHead->next;
    		if(!pNext){
    			return pHead;
    		}else{
    			reverseHead = ReverseList(pNext);
    			pNext->next = pHead;
    			pHead->next = NULL;
    		}
    	}

    	return reverseHead;

    }
};