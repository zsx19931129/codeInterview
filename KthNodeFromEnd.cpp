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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(k == 0 || pListHead == NULL){
    		return NULL;
    	}

    	ListNode* ahead = pListHead;
    	ListNode* behind = pListHead;

    	for(int i=0;i<k-1;i++){
    		if(behind->next){
    			behind = behind->next;
    		}else{
    			return NULL;
    		}
    	}

    	while(behind->next){
    		ahead = ahead->next;
    		behind = behind->next;
    	}

    	return ahead;
    }
};