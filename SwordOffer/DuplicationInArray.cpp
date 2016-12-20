class Solution {
public:
	inline void mySwap(int &a, int &b){
		int tmp = a;
		a = b;
		b = tmp;
	}
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length<2){
        	return false;
        }

        for(int i=0;i<length;i++){
        	if(numbers[i]<0 || numbers[i]>length-1){
        		return false;
        	}
        }

        for(int i=0;i<length;i++){
        	while(numbers[i] != i){
        		if(numbers[i] == numbers[numbers[i]]){
        			*duplication = numbers[i];
        			return true;
        		}
        		mySwap(numbers[i], numbers[numbers[i]]);
        	}
        }
        return false;
    }
};