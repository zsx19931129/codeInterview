#include <string>

using namespace std;


class Solution {
public:
	void mySwap(char &a, char &b){
		char tmp = a;
		a = b;
		b = tmp;
	}
	void rotateStr(string &str, int begin, int end){
		for(int i=begin, j = end;i<j;i++,j--){
			mySwap(str[i],str[j]);
		}
	}
    string ReverseSentence(string str) {
        int slen = str.length();

        rotateStr(str, 0, slen-1);

        int pBegin=0, pEnd=0;
        while(pBegin<slen){
        	if(str[pBegin] == ' '){
        		pBegin++;
        		pEnd++;
        	}else if(str[pEnd] == ' ' || pEnd == slen){
        		rotateStr(str, pBegin, --pEnd);
        		pBegin = ++pEnd;
        	}else{
        		pEnd++;
        	}
        }

        return str;
    }
};