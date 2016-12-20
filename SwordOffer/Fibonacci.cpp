//斐波那契数列结算有logn的算法

class Solution {
public:
    int Fibonacci(int n) {
    	int fi[3] = {0,1,1};
    	if(n<=2){
    		return fi[n];
    	}
    	int fib, fibMinus1=fi[2], fibMinus2 = fi[1]; 
    	for(int i=3;i<=n;i++){
    		fib = fibMinus1 + fibMinus2;
    		fibMinus2 = fibMinus1;
    		fibMinus1 = fib;
    	}
    	return fib;
    }
};