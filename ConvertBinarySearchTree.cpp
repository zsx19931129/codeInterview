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
	// pLastNodeOfList有可能被改变，所以用指针的指针
	void ConvertBST2List(TreeNode *pRootOfTree, TreeNode **pLastNodeOfList){
		if(!pRootOfTree){
			return ;
		}

		if(pRootOfTree->left){
			ConvertBST2List(pRootOfTree->left, pLastNodeOfList);
		}

		if(*pLastNodeOfList){
			(*pLastNodeOfList)->right = pRootOfTree;
			pRootOfTree->left = *pLastNodeOfList;
		}

		*pLastNodeOfList = pRootOfTree;

		if(pRootOfTree->right){
			ConvertBST2List(pRootOfTree->right, pLastNodeOfList);
		}

	}

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNodeOfList = NULL;

        ConvertBST2List(pRootOfTree, &pLastNodeOfList);

        TreeNode* pHeadNodeOfList = NULL;
        if(pLastNodeOfList){
        	pHeadNodeOfList = pLastNodeOfList;
        	while(pHeadNodeOfList->left){
        		pHeadNodeOfList = pHeadNodeOfList->left;
        	}
        }

        return pHeadNodeOfList;

    }
};