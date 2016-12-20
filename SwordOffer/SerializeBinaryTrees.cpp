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

#include <cstring>
#include <cstdio>
#include <cstdlib>
#define MAXLEN 1000
#define TMPLEN 100
char buf[MAXLEN];
char tmp[TMPLEN];

class Solution {
public:
    void serializeImpl(TreeNode *root, char **bufp){
        if(!root){
            (*bufp)[0] = ',';
            (*bufp)[1] = '$';
            (*bufp) += 2;
            return ;
        }
        sprintf(tmp, ",%d", root->val);
        int slen = strlen(tmp);
        strcpy(*bufp, tmp);
        (*bufp) += slen;
        serializeImpl(root->left, bufp);
        serializeImpl(root->right, bufp);
    }
    char* Serialize(TreeNode *root) {    
        memset(buf, 0, sizeof(buf));
        if(!root){
            buf[0] = '$';
            return buf;
        }
        char *bufp = buf;
        serializeImpl(root, &bufp);
        return buf;
    }

    bool getNum(const char *str, int &start, int &num){
        if(str[start] == '\0'){
            return false;
        }

        int off = start;
        if(str[off] == ','){
            off++;
            start++;
        }

        while(str[off] != '\0' && str[off] != ','){
            off++;
        }

        char numbuf[11] = {0};
        strncpy(numbuf, str+start, off-start);
        start = off;
        if(numbuf[0] == '$'){
            return false;
        }else{
            num = atoi(numbuf);
            return true;
        }
    }

    TreeNode* deserializeImpl(const char *str, int &start){
        int num;
        if(getNum(str, start, num)){
            TreeNode *root = new TreeNode(num);
            root->left = deserializeImpl(str, start);
            root->right = deserializeImpl(str, start);
            return root;
        }else{
            return NULL;
        }
    }

    TreeNode* Deserialize(char *str) {
        if(!str || strlen(str) == 0){
            return NULL;
        }
        int start = 0;
        return deserializeImpl(str, start);
    }
};