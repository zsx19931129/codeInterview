class Solution {
public:
    void myswap(char &a, char &b){
        char tmp = a;
        a = b;
        b = tmp;
    }
    string rotateString(const string &str, int begin, int end){
        int slen = str.length();
        string sub = str.substr(begin, end - begin + 1);
        for(int i=0, j=sub.length()-1;i<j;i++, j--){
            myswap(sub[i], sub[j]);
        }
        
        string res = "";
        
        if(begin>0){
            res += str.substr(0, begin);
        }
        res += sub;
        if(end<slen-1){
            res += str.substr(end+1, slen-end-1 );
        }
        return res;
    }
    string LeftRotateString(string str, int n) {
        string res;
        
        int slen = str.length();
        if(slen == 0){
            return res;
        }
        n %= slen;
        
        
        res = rotateString(str, 0, slen-1);
        res = rotateString(res, 0, slen-1-n);
        res = rotateString(res, slen-n, slen-1);
        
        return res;
    }
};