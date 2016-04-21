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

#include <deque>

using namespace std;

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ret;
        if(!pRoot){
        	return ret;
        }
        vector<int> layer;
        deque<TreeNode *> dequeNode;
        dequeNode.push_back(pRoot);
        int toBeVistied = 1;
        int nextLayerCnt = 0;
        while(!dequeNode.empty()){
        	TreeNode *tmp = dequeNode.front();
        	layer.push_back(tmp->val);
        	dequeNode.pop_front();
        	toBeVistied--;
        	if(tmp->left){
        		dequeNode.push_back(tmp->left);
       			nextLayerCnt++;
        	}
        	if(tmp->right){
        		dequeNode.push_back(tmp->right);
        		nextLayerCnt++;
        	}

        	if(toBeVistied == 0){
        		ret.push_back(layer);
        		layer.clear();
        		toBeVistied = nextLayerCnt;
        		nextLayerCnt = 0;
        	}
        }
        return ret;
    }
    
};