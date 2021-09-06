class Solution {
public:
    int mySqrt(int x) {
		int left = 0;
		int right = x;
		while (left <= right) {
			int middle = left + ((right - left) >> 1);
			if (middle == 0){
				left = middle +1;
				continue;
			}
			if (x/middle < middle){
				right = middle - 1;
			}
			else if (x/middle > middle){
				left = middle + 1;
			} 
			else {
				return middle;
			}
		}
		return right;
    }
};
