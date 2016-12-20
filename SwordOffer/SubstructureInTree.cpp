/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	bool have(TreeNode *pRoot1, TreeNode *pRoot2){
		if(!pRoot2){
			return true; 
		}

		if(!pRoot1){
			//上一个if没有return说明pRoot2不为空
			return false;
		}

		if(pRoot1->val != pRoot2->val){
			return false;
		}

		return have(pRoot1->left, pRoot2->left) && have(pRoot1->right, pRoot2->right);
	}

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	bool result = false;

    	if(pRoot1 != NULL && pRoot2 != NULL){

    		if(pRoot1->val == pRoot2->val){
    			result = have(pRoot1, pRoot2);
    		}

    		if(!result){
    			result = HasSubtree(pRoot1->left, pRoot2);
    		}

    		if(!result){
    			result = HasSubtree(pRoot1->right, pRoot2);
    		}
    	}

    	return result;
    }
};