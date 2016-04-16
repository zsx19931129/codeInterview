#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
		int vsize = numbers.size();
		if(vsize == 0){
			return false;
		}
		sort(numbers.begin(), numbers.end());

		int cnt = 0;
		int lastNum = 0;
		for(int i=0;i<vsize;i++){
			if(numbers[i] == 0){
				cnt++;
			}

			if(numbers[i] == lastNum && lastNum != 0){
				return false;
			}else{
				if(lastNum == 0){
					lastNum = numbers[i];
					continue;
				}

				if(numbers[i] - lastNum - 1 > cnt){
					return false;
				}else{
					cnt -= numbers[i] - lastNum - 1;
					lastNum = numbers[i]; 
				}
			}
		}
		return true;
    }
};