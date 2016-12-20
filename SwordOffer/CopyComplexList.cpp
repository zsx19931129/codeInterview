/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
	void CloneNodes(RandomListNode* pHead){
		RandomListNode *pNode = pHead;

		while(pNode){
			RandomListNode *tmp = new RandomListNode(pNode->label);
			tmp->next = pNode->next;
			pNode->next = tmp;
			pNode = tmp->next;
		}
	}

	void ConnectSiblingNodes(RandomListNode *pHead){
		RandomListNode *pNode = pHead;

		while(pNode){
			RandomListNode *tmp = pNode->next;

			if(pNode->random){
				tmp->random = pNode->random->next;
			}

			pNode = tmp->next;
		}
	}

	RandomListNode* ReconnectNodes(RandomListNode* pHead){
		RandomListNode* pNode = pHead;
		RandomListNode* pClonedHead = NULL;
		RandomListNode* pClonedNode = NULL;

		if(pNode != NULL){
			pClonedNode = pNode->next;
			pClonedHead = pClonedNode;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}

		while(pNode){
			pClonedNode->next = pNode->next;
			pClonedNode = pClonedNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}

		return pClonedHead;
	}

    RandomListNode* Clone(RandomListNode* pHead)
    {
    	CloneNodes(pHead);
    	ConnectSiblingNodes(pHead);
    	return ReconnectNodes(pHead);
    }
};