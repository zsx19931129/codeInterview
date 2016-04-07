class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        if(len == 0){
        	return 0;
        }

        int minIdx = 0;
        int left = 0, right = len-1;
        bool find = false;
        while(rotateArray[left] >= rotateArray[right]){
        	if(left+1 == right){
        		minIdx = right;
        		break;
        	}
        	int mid = (left + right)/2;
        	if(rotateArray[left] == rotateArray[right]){
        		// 如果两个数相同只能顺序比较
        		for(int i = left;i<=right;i++){
        			if(rotateArray[i] < rotateArray[left]){
        				minIdx = i;
        				break;
        			}
        		}
        		return rotateArray[minIdx];

        	}else{
        		if(rotateArray[left] > rotateArray[mid]){
        			right = mid;
        		}else{
        			left = mid;
        		}
        	}
        }
        return rotateArray[minIdx];
    }
};