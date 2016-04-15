/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

#include <cmath>
class Solution {
public:
	int getLength(ListNode *list){
		int ret = 0;
		while(list){
			ret++;
			list = list->next;
		}
		return ret;
	}
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);

        int sub = abs(len1 - len2);
        if(len1>len2){
        	for(int i=0;i<sub;i++){
        		pHead1 = pHead1->next;
        	}
        }else{
        	for(int i=0;i<sub;i++){
        		pHead2 = pHead2->next;
        	}
        }

        ListNode *ret = NULL;
        while(pHead1 && pHead2){
        	if(pHead1 == pHead2){
        		ret = pHead1;
        		break;
        	}
        	pHead1 = pHead1->next;
        	pHead2 = pHead2->next;

        }
        return ret;
    }
};