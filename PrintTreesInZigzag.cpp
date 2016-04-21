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

#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ret;
        if(!pRoot){
            return ret;
        }

        //两个stack，奇数层偶数层有区分
        stack<TreeNode *> mystk[2];
        int curStk = 0;
        mystk[curStk].push(pRoot);
        vector<int> layer;
        while(!mystk[curStk].empty()){
            layer.clear();
            while(!mystk[curStk].empty()){
                TreeNode *cur = mystk[curStk].top();
                if(curStk == 0){
                    if(cur->left){
                        mystk[1].push(cur->left);
                    }
                    if(cur->right){
                        mystk[1].push(cur->right);
                    }
                }else if(curStk == 1){
                    if(cur->right){
                        mystk[0].push(cur->right);
                    }
                    if(cur->left){
                        mystk[0].push(cur->left);
                    }
                }else{
                    cout<<"you cannot reach here!!"<<endl;
                }
                mystk[curStk].pop();
                layer.push_back(cur->val);
            }

            ret.push_back(layer);
            curStk = 1 - curStk;
        }
        return ret;
    }
    
};