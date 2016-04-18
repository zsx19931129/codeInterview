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
	ListNode* findMeetingNodeInLoop(ListNode* pHead){
		ListNode *pSlow = pHead, *pFast = pHead;

		pSlow = pSlow->next;
		if(pSlow){
			pFast = pSlow->next;
		}

		while(pSlow && pFast){
			if(pSlow == pFast){
				return pSlow;
			}

			pSlow = pSlow->next;

			pFast = pFast->next;
			if(pFast){
				pFast = pFast->next;
			}
		}
		return NULL;
	}
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	if(!pHead){
    		return NULL;
    	}
    	ListNode* meetingNode = findMeetingNodeInLoop(pHead);

    	if(!meetingNode){
    		return NULL;
    	}

    	//得到环中节点的个数
    	ListNode* curNode = meetingNode->next;
    	int cnt = 1;
    	while(curNode!=meetingNode){
    		curNode = curNode->next;
    		cnt++;
    	}

    	ListNode* p1 = pHead;
    	ListNode* p2 = pHead;
    	for(int i=0;i<cnt;i++){
    		p1 = p1->next;
    	}

    	while(p1!=p2){
    		p1 = p1->next;
    		p2 = p2->next;
    	}

    	return p1;
    }
};