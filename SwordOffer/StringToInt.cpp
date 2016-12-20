enum status{valid=0, invalid};
int g_nstatus = valid;

class Solution {
public:
	long long StrToIntImpl(const string &str, bool minus){
		long long num = 0;
		int slen = str.length();
		int i=0;
		int flag = minus ? -1 : 1;
		for(;i<slen;i++){
			if(str[i]>='0' && str[i]<= '9'){
				num = num*10 + flag*(str[i]-'0');
				if( (minus && num < (signed int)0x80000000) || (!minus && num > (signed int)0x7fffffff)){
					num = 0;
					break;
				}
			}else{
				num = 0;
				break;
			}
		}
		if(i==slen){
			g_nstatus = valid;
		}
		return num;
	}
    int StrToInt(string str) {
        int slen = str.length();
        g_nstatus = invalid;
        long long num = 0;

        if(slen > 0){
        	bool minus = false;
        	int start = 0;
        	if(str[0] == '+'){
        		start++;
        	}else if(str[0] == '-'){
        		minus = true;
        		start++;
        	}

        	if(start < slen){
        		//不是只含有符号的情况
        		num = StrToIntImpl(str.substr(start), minus);
        	}
        }
        return (int)num;
    }
};