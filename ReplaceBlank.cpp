class Solution {
public:
	void replaceSpace(char *str,int length) {
		int scnt = 0;
		for(int i=0;i<length;i++){
			if(str[i] == ' '){
				scnt++;
			}
		}
		char *front = str + (length - 1);
		char *back = str + (length - 1 + 2*scnt);

		while(front!=back){
			if(*front == ' '){
				*back = '0';
				*(back-1) = '2';
				*(back-2) = '%';
				back -= 3;
				front--;
			}else{
				*back = *front;
				front--;
				back--;
			}
		}
	}
};