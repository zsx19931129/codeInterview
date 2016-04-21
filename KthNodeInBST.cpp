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
	TreeNode* inOrderTraverse(TreeNode *root, unsigned int &k){
		TreeNode *res = NULL;

		if(root->left){
			res = inOrderTraverse(root->left, k);
		}

		if(res == NULL){
			if(k == 1){
				res = root;
			}else{
				k--;
			}
		}
		
		if(res == NULL && root->right){
			res = inOrderTraverse(root->right, k);
		}

		return res;
	}

    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
    	if(!pRoot || k<1){
    		return NULL;
    	}
        return inOrderTraverse(pRoot, k);
    }

    
};