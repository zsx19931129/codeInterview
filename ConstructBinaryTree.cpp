/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>

 using namespace std;

class Solution {
public:
	TreeNode* constructRecursive(const vector<int> &pre, int ph, int pt, 
								const vector<int> &in, int ih, int it){
		TreeNode* rt = new TreeNode(pre[ph]);

		if(ph == pt){
			if(ih != it || ph != pt){
				//说明前序遍历和中序遍历不一致
				return NULL;
			}else{
				return rt;
			}
		}

		int i = ih; 
		for(;i<=it;i++){
			if(pre[ph] == in[i]){
				break;
			}
		}
		if(i>it){
			return NULL;
		}

		int leftCnt = i - ih;
		if(leftCnt > 0){
			rt->left = constructRecursive(pre, ph+1, ph+leftCnt, in, ih, i-1);
		}
		if(leftCnt < pt - ph){
			//说明有右子树
			rt->right = constructRecursive(pre, ph+leftCnt+1, pt, in, i+1, it);
		}

		return rt;
	}

    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
    	int length = pre.size();
    	if(length != in.size() || length == 0){
    		return NULL;
    	}

    	TreeNode *root = constructRecursive(pre, 0, length-1, in, 0, length - 1);
    	return root;
    }
};