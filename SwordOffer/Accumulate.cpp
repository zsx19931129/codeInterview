// 求1到n的和无外乎公式（乘除法不可用），递归（需要解决if条件判定），循环（如何不用关键字实现）

class calculateSum{
public:
    calculateSum(){
        i++;
        sum += i;
    }
    static void reset(){
        i = 0;
        sum = 0;
    }
    static unsigned int getSum(){
        return sum;
    }
private:
    static unsigned int i;
    static unsigned int sum; 
};

unsigned int calculateSum::i = 0;
unsigned int calculateSum::sum = 0;

class A;
class B;

A* myarray[2];

class A{
public:
    virtual int solve(int n){
        return 0;
    }
};

class B:public A{
public:
    virtual int solve(int n){
        // 两次取非转换成bool值
        return myarray[!!n]->solve(n-1) + n;
    }
};

typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_terminate(unsigned int n){
    return 0;
}

unsigned int Solution3_Sum(unsigned int n){
    static fun f[2] = {Solution3_terminate, Solution3_Sum};
    return f[!!n](n-1) + n;
}

template <unsigned int n> struct Solution4_sum
{
    unsigned int sum= Solution4_sum<n-1>().sum + n;
};

template <> struct Solution4_sum<1>{
    unsigned int sum = 1;
};

class Solution {
public:
    int Solution1(int n){
        // 循环本质上是执行同一段代码，创建指定个数的对象可以实现同样的效果
        new calculateSum[100];
        return calculateSum::getSum();
    }
    int Solution2(int n){
        //利用虚函数求解
        A a;
        B b;
        myarray[0] = &a;
        myarray[1] = &b;

        return myarray[1]->solve(n);
    }
    int Solution3(int n){
        //利用函数指针，可用于C语言
        return Solution3_Sum(n);
    }
    int Solution4(int n){
        // 利用模板求解
        //缺点：只能在编译时就确定
        Solution4_sum<100> a;
        return a.sum;
    }
    int Sum_Solution(int n) {
        if(n<1){
            return 0;
        }
        //int res = Solution1(n);
        //int res = Solution2(n);
        int res = Solution3(n);
        //int res = Solution4(n);
        return res;
    }
};