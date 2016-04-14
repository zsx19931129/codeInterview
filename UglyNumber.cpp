// 空间换时间，所有新产生的丑数都可以由已经产生的丑数*2或*3或*5生成，选取其中最小的那个，用三个
// 指针分别指向已产生的数中*235最接近当前最大丑数的数

class Solution {
public:
	int minTriple(int a, int b, int c){
		int res = a<b ? a : b;
		res = res<c ? res : c;
		return res;
	}
    int GetUglyNumber_Solution(int index) {
    	if(index <= 0){
    		return 0;
    	}

    	int *uglyNumbers = new int[index];

    	uglyNumbers[0] = 1;
    	int curIdx = 0;

    	int *ptMulti2 = uglyNumbers;
    	int *ptMulti3 = uglyNumbers;
    	int *ptMulti5 = uglyNumbers;

    	//注意循环的终止条件
    	while(curIdx < index-1){
    		while(*ptMulti2 * 2 <= uglyNumbers[curIdx]){
    			ptMulti2++;
    		}
    		while(*ptMulti3 * 3 <= uglyNumbers[curIdx]){
    			ptMulti3++;
    		}
    		while(*ptMulti5 * 5 <= uglyNumbers[curIdx]){
    			ptMulti5++;
    		}

    		uglyNumbers[++curIdx] = minTriple(*ptMulti2 * 2, *ptMulti3 * 3, *ptMulti5 * 5 );
    	}

    	int ret = uglyNumbers[index-1];
    	delete[] uglyNumbers;
    	return ret;
    }
};