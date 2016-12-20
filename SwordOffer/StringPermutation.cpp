#include <algorithm>

using namespace std;

class Solution {
public:
	void Permutation(string &str, int pBegin, vector<string> &res){
		if(pBegin == str.length()){
			res.push_back(str);
			return ;
		}

		for(int i=pBegin;i<str.length();i++){
			//避免重复只需要加这一句
			if(i!=pBegin && str[i] == str[pBegin]){
				continue ;
			}

			int tmp = str[i];
			str[i] = str[pBegin];
			str[pBegin] = tmp;

			Permutation(str, pBegin+1, res);

			tmp = str[pBegin];
			str[pBegin] = str[i];
			str[i] = tmp;
		}

	}
    vector<string> Permutation(string str) {
        int len = str.length();
        vector<string> res;

        if(len == 0){
        	return res;
        }

        Permutation(str, 0, res);

        sort(res.begin(), res.end());

        return res;
    }
};