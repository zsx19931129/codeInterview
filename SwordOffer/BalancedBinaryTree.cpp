class Solution {
public:
	bool isBalancedImpl(TreeNode *pRoot, int &depth){
		if(pRoot == NULL){
			depth = 0;
			return true;
		}

		int left, right;
		if( isBalancedImpl(pRoot->left, left) && isBalancedImpl(pRoot->right, right) ){
			int sub = left - right;
			if(sub >= -1 && sub <= 1){
				depth = left>right ? left+1 : right+1;
				return true;
			}
		}

		return false;
	}
    bool IsBalanced_Solution(TreeNode* pRoot) {
    	int depth = 0;
    	return isBalancedImpl(pRoot, depth);
    }
};