class Solution {
public:

	int GetFirstK(vector<int> data, int k, int begin, int end){
		if(begin>end){
			return -1;
		}

		int mid = (begin + end)>>1;
		if(data[mid] == k){
			if(mid>0 && data[mid-1] != k || mid == 0){
				return mid;
			}else{
				end = mid-1;
			}
		}else if(data[mid]>k){
			end = mid-1;
		}else if(data[mid]<k){
			begin = mid+1;
		}
		return GetFirstK(data, k, begin, end);
	}

	int GetLastK(vector<int> data, int k, int begin, int end){
		if(begin>end){
			return -1;
		}

		int mid = (begin + end)>>1;
		if(data[mid] == k){
			if(mid<data.size()-1 && data[mid+1] != k || mid == data.size()-1){
				return mid;
			}else{
				begin = mid+1;
			}
		}else if(data[mid]>k){
			end = mid-1;
		}else if(data[mid]<k){
			begin = mid+1;
		}
		return GetLastK(data, k, begin, end);
	}	

    int GetNumberOfK(vector<int> data ,int k) {
        int vsize = data.size();

        int res = 0;

        if(vsize>0){
        	int firstK = GetFirstK(data, k, 0, vsize-1);
        	int lastK = GetLastK(data, k, 0, vsize-1);

        	if(firstK!=-1 && lastK != -1){
        		res = lastK - firstK + 1;
        	}
        }

        return res;
    }
};