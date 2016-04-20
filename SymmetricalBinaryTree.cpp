/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
	bool determine(TreeNode* p1, TreeNode* p2){
		if(p1 != NULL && p2 == NULL || p1 == NULL && p2 != NULL){
			return false;
		}else if(p1 == NULL && p2 == NULL){
			return true;
		}else{
			if(p1->val != p2->val){
				return false;
			}else{
				return determine(p1->left, p2->right) && determine(p1->right, p2->left);
			}
		}

	}

    bool isSymmetrical(TreeNode* pRoot)
    {
    	return determine(pRoot, pRoot);
    }

};