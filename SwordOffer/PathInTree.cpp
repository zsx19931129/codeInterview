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
	void FindPath(TreeNode* root, int expectNumber, vector<vector<int> > &res, 
		vector<int> &path, int currentSum){
		int val = root->val;

		path.push_back(val);
		currentSum += val;

		if(currentSum == expectNumber && (root->left == NULL && root->right == NULL)){
			res.push_back(path);
		}

		if(root->left){
			FindPath(root->left, expectNumber, res, path, currentSum);
		}
		if(root->right){
			FindPath(root->right, expectNumber, res, path, currentSum);
		}

		path.pop_back();
	}
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    	vector<vector<int> > res;
    	vector<int> path;
    	int currentSum = 0;

    	if(!root){
    		return res;
    	}

    	FindPath(root, expectNumber, res, path, currentSum);

    	return res;
    }
};