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
        }else if(pNode->next){
        	TreeLinkNode* curNode = pNode;
        	while(curNode->next && curNode->next->left != curNode){
        		curNode = curNode->next;
        	}

        	return curNode->next;
        }else{
        	return NULL;
        }
    }
};