#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void printNumber(char *mynum, int length){
    bool isZeroBit = true;
    for(int i=0;i<length;i++){
        if(mynum[i] != '0'){
            isZeroBit = false;
        }
        if(!isZeroBit){
            printf("%c", mynum[i]);
        }
    }
    //TBD:用递归方法不输出0的方法
    if(!isZeroBit)
    	printf("\n");
    //printf("debug:%s\n", mynum);
}

bool Increment(char *num, int length){
    int carryBit = 0;
    for(int i=length-1;i>=0;i--){
        int cur = num[i] - '0' + carryBit;
        if(i == length-1){
            cur++;
        }
        
        if(cur == 10){
            if(i == 0){
                return false;
            }else{
                num[i] = '0';
                carryBit = 1;
            }
        }else{
            num[i] = cur + '0';
            carryBit = 0;
        }
    }
    return true;
}

void printNDigitsBigNum(int n){
    if(n<=0){
        return ;
    }
    
    char* mynum = new char[n+1];
    memset(mynum, '0', n);
    mynum[n] = '\0';
    
    while(Increment(mynum, n)){
        printNumber(mynum, n);
    }
    
    delete[] mynum;
}

void recursiveFunc(int cur, char* mynum, int length){
    for(int i=0;i<10;i++){
        mynum[cur] = i + '0';
        if(cur == length - 1){
            printNumber(mynum, length);
        }else{
            recursiveFunc(cur+1, mynum, length);
        }
    }
}

void printNDigitsRecursively(int n){
    if(n<=0){
        return ;
    }
    
    char *mynum = new char[n+1];
    memset(mynum, '0', n-1);
    mynum[n] = '\0';
    
    recursiveFunc(0, mynum, n);
    
    delete[] mynum;
}

int main(){
    int n;
    cin>>n;
    //printNDigitsBigNum(n);
    printNDigitsRecursively(n);
}