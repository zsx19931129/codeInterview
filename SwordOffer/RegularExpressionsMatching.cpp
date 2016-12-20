class Solution {
public:
	bool matchImpl(char* str, char* pattern){
		if(*str == '\0' && *pattern == '\0'){
			return true;
		}

		if(*str != '\0' && *pattern == '\0'){
			return false;
		}

		if(*(pattern+1) == '*'){
			if(*str == *pattern || (*str != '\0' && *pattern == '.')){
				// 分别表示停留在这个匹配，忽略这个匹配和进入下一个匹配
				return (matchImpl(str+1, pattern)) || (matchImpl(str, pattern+2)) || (matchImpl(str+1, pattern+2));
			}else{
				// 忽略这个*匹配
				return matchImpl(str, pattern+2);
			}
		}

		if( (*str == *pattern) || (*str != '\0' && *pattern == '.') ){
			return matchImpl(str+1, pattern+1);
		}

		return false;
	}
    bool match(char* str, char* pattern)
    {
    	if(str == NULL || pattern == NULL){
    		return false;
    	}

    	return matchImpl(str, pattern);
    }
};