// 优化原来的O(n^2)算法，采用归并排序的思想，不断计算相邻元组的逆序对，然后不断归并，时间复杂度O(nlogn)
// 归并排序需要O(n)的辅助空间，是一种空间换时间的思想
class Solution {
public:
	int InversePairsImpl(vector<int> &data, vector<int> &copy, int begin, int end){
		if(begin == end){
			copy[begin] = data[begin];
			return 0;
		}

		int mid = (end + begin)>>1;

		int ret = 0;

		ret += InversePairsImpl(copy, data, begin, mid);
		ret += InversePairsImpl(copy, data, mid+1, end);

		//归并过程
		int pt1 = mid, pt2 = end;
		int ptcp = end;
		cout<<"begin:"<<begin<<" "<<"end:"<<end<<" ret:"<<ret<<endl;

		while(pt1 >= begin && pt2 >= mid+1){
			if(data[pt1] <= data[pt2]){
				copy[ptcp] = data[pt2];
				pt2--;
				ptcp--;
			}else{
				copy[ptcp] = data[pt1];
				ptcp--;
				pt1--;
				//ret += pt2-(mid+1)+1; 
				ret += pt2-mid;
			}
		}

		while(pt1>=begin){
			copy[ptcp] = data[pt1];
			ptcp--;
			pt1--;
		}

		while(pt2>=mid+1){
			copy[ptcp] = data[pt2];
			ptcp--;
			pt2--;
		}
		cout<<"ret:"<<ret<<endl;
		return ret;
	}
    int InversePairs(vector<int> data) {
        int vsize = data.size();

        if(vsize < 2){
        	return 0;
        }

        // int *copy = new int[vsize];
        // for(int i=0;i<vsize;i++){
        // 	copy[i] = data[i];
        // }
        vector<int> copy(data);

        int res = InversePairsImpl(data, copy, 0, vsize-1);

        return res;
    }
};