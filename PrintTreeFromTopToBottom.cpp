#include <deque>

using namespace std;

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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
    	vector<int> res;
    	if(!root){
    		return res;
    	}

    	deque<TreeNode *> dequeTreeNode;

    	dequeTreeNode.push_back(root);

    	while(!dequeTreeNode.empty()){
    		TreeNode *cur = dequeTreeNode.front();
    		dequeTreeNode.pop_front();
    		res.push_back(cur->val);
    		if(cur->left == NULL && cur->right == NULL){
    			continue ;
    		}else{
    			if(cur->left){
    				dequeTreeNode.push_back(cur->left);
    			}
    			if(cur->right){
    				dequeTreeNode.push_back(cur->right);
    			}
    		}
    	}
    	return res;
    }
};