class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int charCnt[256]={0};

        int slen = str.length();

        for(int i=0;i<slen;i++){
            charCnt[str[i]]++;
        }

        for(int i=0;i<slen;i++){
            if(charCnt[str[i]] == 1){
                return i;
            }
        }

        //没有只出现一次的字符
        return -1;
    }
};