// 计算n个骰子所有可能出现的和的概率

#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

const int g_maxValue = 6;

// 方法一，递归实现，效率低
void Probability(int number, int *pProbabilities);
void Probability(int original, int current, int sum, int *pProbabilities);

void Probability_Solution1(int number){
	if(number < 1){
		return ;
	}

	int maxSum = number * g_maxValue;
	int *pProbabilities = new int[maxSum-number+1];
	for(int i=number;i<=maxSum;i++){
		pProbabilities[i-number] = 0;
	}

	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);

	for(int i=number;i<=maxSum;i++){
		double ratio = pProbabilities[i-number]/total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities;
}

void Probability(int number, int *pProbabilities){
	for(int i=1;i<=g_maxValue;i++){
		Probability(number, number, i, pProbabilities);
	}
}

void Probability(int original, int current, int sum, int *pProbabilities){
	if(current == 1){
		pProbabilities[sum - original]++;
	}else{
		for(int i=1;i<=g_maxValue;i++){
			Probability(original, current-1, sum+i, pProbabilities);
		}
	}
}

//方法二，动态规划思想
void Probability_Solution2(int number){
	if(number<1){
		return ;
	}

	int maxSum = number * g_maxValue;

	int *pProbabilities[2];
	pProbabilities[0] = new int[maxSum+1];
	pProbabilities[1] = new int[maxSum+1];

	int flag = 0;
	//第一个骰子
	for(int i=1;i<=g_maxValue;i++){
		pProbabilities[flag][i] = 1;
	}

	for(int i=2;i<=number;i++){
		//小于当前数的都不可能
		for(int j=0;j<i;j++){
			pProbabilities[1-flag][j] = 0;
		}

		for(int j=i;j<=i*g_maxValue;j++){
			pProbabilities[1-flag][j] = 0;

			for(int k=1;k<=j && k<=g_maxValue;k++){
				pProbabilities[1-flag][j] += pProbabilities[flag][j-k];
			}
		}

		flag = 1-flag;
	}

	double total = pow( (double)g_maxValue, number );

	for(int i=number;i<=number*g_maxValue;i++){
		double ratio = (double)pProbabilities[flag][i] / total;
		printf("%d %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

// 测试代码
void Test(int n){
	printf("Test for %d begins:\n", n);

	printf("Test for solution1\n");
	Probability_Solution1(n);

	printf("Test for solution2\n");
	Probability_Solution2(n);

	printf("\n");
}

int main(){
	Test(1);
	Test(2);
	Test(3);
	Test(4);

	Test(11);

	Test(0);

	return 0;
}