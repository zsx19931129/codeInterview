// https://leetcode.com/discuss/44281/4-lines-o-log-n-c-java-python

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	int ones = 0;
    	for(long long int m=1;m<=n;m*=10){
    		int a = n/m;
    		int b = n%m;

    		ones += (a+8)/10 * m + (a%10 == 1)*(b+1);
    	}
    	return ones;
    }
};