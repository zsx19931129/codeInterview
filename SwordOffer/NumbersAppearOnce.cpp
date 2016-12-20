class Solution {
public:
	int FindFirstBitIs1(int num){
		int index = 0;
		//注意运算优先级
		while( ((num & 1) == 0) && (index < 8*sizeof(int)) ){
			num = num>>1;
			index++;
		}
		return index;
	}

	bool isBit1(int num, int index){
		num = num>>index;
		return num&1;
	}

    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    	int vsize = data.size();
    	if(vsize<2){
    		return ;
    	}
    	*num1 = *num2 = 0;
    	int resExclusiveOr = 0;
    	for(int i=0;i<vsize;i++){
    		resExclusiveOr ^= data[i];
    	}
    	//由于两个数不同，一定可以得到一个不为0的数，意味着肯定至少有一位是1
    	int indexOfOne = FindFirstBitIs1(resExclusiveOr);

    	for(int i=0;i<vsize;i++){
    		if(isBit1(data[i], indexOfOne)){
    			*num1 ^= data[i];
    		}else{
    			*num2 ^= data[i];
    		}
    	}
    }
};