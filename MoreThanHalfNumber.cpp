#include <random>
#include <ctime>
#include <iostream>
#include <exception>
using namespace std;

class Solution {
public:
	int RandomInRange(int start, int end){
		default_random_engine random(time(NULL));
		uniform_int_distribution<int> dis(start, end);

		return dis(random);
	}

	void Swap(int &a, int &b){
		int tmp = a;
		a = b;
		b = tmp;
	}

	int partition(vector<int> &numbers, int start, int end){
		int vsize = numbers.size();

		if(vsize == 0 || start<0 || end>=vsize){
			cerr<<"exception caught"<<endl;
		}

		int idx = RandomInRange(start, end);
		Swap(numbers[idx], numbers[end]);

		int small = start - 1;
		for(idx = start;idx<end;idx++){
			if(numbers[idx] < numbers[end]){
				++small;
				if(small != idx){
					Swap(numbers[idx], numbers[small]);
				}
			}
		}

		++small;

		Swap(numbers[small], numbers[end]);

		return small;

	}

	bool CheckMoreThanHalf(const vector<int> &numbers, int res){
		int cnt = 0;
		for(int i = 0;i<numbers.size();i++){
			if(numbers[i] == res){
				cnt++;
			}
		}

		return cnt*2>numbers.size();
	}

	int MoreThanHalfNumPartition(vector<int> &numbers){
		int vsize = numbers.size();

		int start = 0;
		int end = vsize - 1;
		int mid = vsize>>1;

		int idx = partition(numbers, start, end);
		while(idx != mid){
			if(idx > mid){
				end = idx-1;
			}else{
				start = idx+1;
			}
			idx = partition(numbers, start, end);
		}

		int res = numbers[mid];
		if(!CheckMoreThanHalf(numbers, res)){
			return 0;
		}

		return res;
	}

	int MoreThanHalfNumOptimize(const vector<int> &numbers){
		int vsize = numbers.size();

		int res = numbers[0];
		int cnt = 1;
		for(int i=1;i<numbers.size();i++){
			if(cnt == 0){
				res = numbers[i];
				cnt = 1;
			}else{
				if(numbers[i] == res){
					cnt++;
				}else{
					cnt--;
				}
			}
		}

		if(!CheckMoreThanHalf(numbers, res)){
			return 0;
		}

		return res;
	}

    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	// 利用快排partition, 时间复杂度O(n)，证明复杂，可见算法导论
    	int vsize = numbers.size();

    	if(vsize == 0){
    		return 0;
    	}

    	int res = MoreThanHalfNumPartition(numbers);
    	//int res = MoreThanHalfNumOptimize(numbers);

    	return res;
    }
};