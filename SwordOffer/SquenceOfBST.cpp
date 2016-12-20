	class Solution {
	public:
		bool verifyImpl(const vector<int> &sequence, int l, int r){
			int root = sequence[r];

			int i = l;
			for(;i<r;i++){
				if(sequence[i]>root){
					break;
				}
			}

			int j = i;
			for(;j<r;j++){
				if(sequence[j]<root){
					return false;
				}
			}

			bool left = true;
			if(i>l){
				left = verifyImpl(sequence, l, i-1);
			}

			bool right = true;
			if(i<r){
				right = verifyImpl(sequence, i,r-1);
			}
			return left && right;
		}

	    bool VerifySquenceOfBST(vector<int> sequence) {
	    	int len = sequence.size();

	    	if(len == 0){
	    		return false;
	    	}

	    	return verifyImpl(sequence, 0, len - 1);
	    }
	};