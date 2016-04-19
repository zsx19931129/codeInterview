using namespace std;
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
	TreeLinkNode* findFirstLeftFather(TreeLinkNode* pNode){
		if(!pNode){
			return NULL;
		}
		if(pNode->next && pNode->next->left == pNode){
			return pNode->next;
		}else{
			return findFirstLeftFather(pNode->next);
		}
	}
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
    	if(!pNode){
    		return NULL;
    	}
        
        if(pNode->right){
        	TreeLinkNode* curNode = pNode->right;
        	while(curNode->left){
        		curNode = curNode->left;
        	}
        	return curNode;
        }else if(pNode->next && pNode->next->left == pNode){
        	return pNode->next;
        }else if(pNode->next && pNode->next->right == pNode){
        	return findFirstLeftFather(pNode->next);
        }else{
        	return NULL;
        }
    }
};