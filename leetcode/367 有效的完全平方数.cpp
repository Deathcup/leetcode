class Solution {
public:
    bool isPerfectSquare(int num) {
		int left = 0;
		int right = num;
		int middle;
		while (left <= right){
			middle = left + ((right - left) >> 1);
			if(middle == 0) left = middle + 1;
			else if (num/middle < middle){
				right = middle - 1;
			}
			else if (num/middle > middle){
				left = middle + 1;
			}
			else{
				if(num%middle == 0) return 1;
				else left = middle + 1;
			}
		}
		return 0;
    }
};
