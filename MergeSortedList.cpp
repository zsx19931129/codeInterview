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
	//递归版本
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
		if(!pHead1){
			return pHead2;
		}else if(!pHead2){
			return pHead1;
		}

		ListNode *mergeRoot = NULL;

		if(pHead1->val<pHead2->val){
			mergeRoot = pHead1;
			mergeRoot->next = Merge(pHead1->next, pHead2);
		}else{
			mergeRoot = pHead2;
			mergeRoot->next = Merge(pHead1, pHead2->next);
		}

		return mergeRoot;
	}

    // ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    // {
    //     if(!pHead1){
    //     	return pHead2;
    //     }else if(!pHead2){
    //     	return pHead1;
    //     }

    //     ListNode* pInsert = NULL;
    //     ListNode* pRead = NULL;
    //     if(pHead1->val < pHead2->val){
    //     	pInsert = pHead1;
    //     	pRead = pHead2;
    //     }else{
    //     	pInsert = pHead2;
    //     	pRead = pHead1;
    //     }

    //     ListNode* curprev = pInsert;
    //     ListNode* curi = pInsert->next;
    //     ListNode* curr = pRead;

    //     while(curi && curr){
    //     	if(curi->val < curr->val){
    //     		curprev = curi;
    //     		curi = curi->next;
    //     	}else{
    //     		ListNode* tmp = curr;
    //     		curr = curr->next;
    //     		curprev->next = tmp;
    //     		tmp->next = curi;
    //     		curprev = tmp;
    //     	}
    //     }

    //     if(!curi){
    //     	curprev->next = curr;
    //     }

    //     return pInsert;
    // }
};