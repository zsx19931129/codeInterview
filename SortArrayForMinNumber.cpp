#define MAXNUMLEN 10

#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
	static bool myStrCmp(const string &a, const string &b){
		string str1 = a+b;
		string str2 = b+a;
		return str1 < str2;
	}
    string PrintMinNumber(vector<int> numbers) {
        int numSize = numbers.size();
        string res = "";
        if(numSize == 0){
        	return res;
        }

        vector<string> strVect;
        char strTmp[MAXNUMLEN+1];
        for(int i=0;i<numSize;i++){
        	sprintf(strTmp, "%d", numbers[i]);
        	strVect.push_back(string(strTmp));
        }

        sort(strVect.begin(), strVect.end(), myStrCmp);

        for(int i=0;i<numSize;i++){
        	res += strVect[i];
        }

        return res;
    }
};