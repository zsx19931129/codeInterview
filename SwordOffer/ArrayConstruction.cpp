class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
		int vsize = A.size();
		vector<int> B(vsize, 1);
		if(vsize < 2){
			return B;
		}

		for(int i=1;i<vsize;i++){
			B[i] = B[i-1]*A[i-1];
		}

		int mult = 1;
		for(int i=vsize-2;i>=0;i--){
			mult *= A[i+1];
			B[i] *= mult;
		}

		return B;
    }
};