class Solution
{
public:
	int idx;
	int occurence[256];
	Solution():idx(0){
		for(int i=0;i<256;i++){
			occurence[i] = -1;
		}
	}
  	//Insert one char from stringstream
    void Insert(char ch)
    {
    	if(occurence[ch] == -1){
    		occurence[ch] = idx;
    		idx++;
    	}else if(occurence[ch] >= 0){
    		//说明已经出现过
    		occurence[ch] = -2;
    	}
    }
  	//return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	int minIdx=257;
    	char ret = '#';
    	for(int i=0;i<256;i++){
    		if(occurence[i]>=0 && occurence[i] < minIdx){
    			minIdx = occurence[i];
    			ret = i;
    		}
    	}
    	return ret;
    }

};