class Solution {
public:
	int scanDigits(char** string){
		int ret = 0;
		while((**string) != '\0' && **string >= '0' && **string <= '9'){
			++(*string);
			ret++;
		}
		return ret;
	}
	bool isExponent(char** string){
		if( (**string)!='E' && (**string) != 'e'){
			return false;
		}else{
			++(*string);
		}

		if( (**string) == '+' || (**string) == '-'){
			++(*string);
		}

		if( (**string) == '\0' ){
			return false;
		}

		int cnt = scanDigits(string);
		if(cnt == 0){
			//return false;
		}
		if((**string) != '\0'){
			return false;
		}

		return true;
	}
    bool isNumeric(char* string)
    {
    	if(string == NULL){
    		return false;
    	}
    	if(*string == '+' || *string == '-'){
    		++string;
    	}

    	if(*string == '\0'){
    		return false;
    	}

    	int cnt = scanDigits(&string);
    	bool numeric = true;
    	if(cnt==0){
    		//没有扫描到数字字符
    		//return false;
    	}

    	if(*string != '\0'){
    		if(*string == '.'){
    			++string;
    			cnt = scanDigits(&string);
    			if(cnt == 0){
    				//return false;
    			}
    			if(*string == 'E' || *string == 'e'){
    				numeric = isExponent(&string);
    			}
    		}else if(*string == 'e' || *string == 'E'){
    			numeric = isExponent(&string);
    		}else{
    			numeric = false;
    		}
    	}
    	if(*string != '\0'){
    		numeric = false;
    	}
    	return numeric;
    }
};