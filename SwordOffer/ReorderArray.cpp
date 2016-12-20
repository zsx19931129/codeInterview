#include <iostream>

using namespace std;

class Solution {
public:
	static bool isOdd(int n){
		return n&1;
	}
	void reorderImpl(vector<int> &array, bool (*func)(int)){
		int len = array.size();

		//基于快排的划分不能保证顺序
		// int left = 0, right = len - 1;
		// while(left < right){
		// 	while((*func)(array[left])){
		// 		left++;
		// 	}

		// 	while(!(*func)(array[right])){
		// 		right--;
		// 	}

		// 	if(left < right){
		// 		int tmp = array[left];
		// 		array[left] = array[right];
		// 		array[right] = tmp;
		// 	}
		// }

		//能够保证顺序的划分，利用一个额外的相同大小的vector
		vector<int> tmp(array);
		int left = 0, right = len - 1;
		for(int i=0;i<len;i++){
			if(tmp[i] & 1){
				array[left++] = tmp[i];
			}else{
				array[right--] = tmp[i];
			}
		}
		// 调换顺序
		for(int i = left, j = len - 1;i<j;i++,j--){
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
    void reOrderArray(vector<int> &array) {
    	if(array.size()==0 || array.size()==1 )
    		return ;
    	reorderImpl(array, isOdd);

    }
};