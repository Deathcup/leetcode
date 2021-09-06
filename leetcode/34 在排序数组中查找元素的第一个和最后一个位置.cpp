class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int n = nums.size() - 1;
		int left = 0;
		int right = n;
		int middle;
		while (left <= right){
			middle = left + ((right-left) >> 1);
			if (nums[middle] > target){
				right = middle - 1;
			}
			else if(nums[middle] < target){
				left = middle + 1;
			}
			else {
				int l = middle, r = middle;
				while(nums[l] == target){
					l--;
					if (l < 0) break;
				}
				while(nums[r] == target)
				{
					r++;
					if (r > n) break;
				}
				return {l+1, r-1};
			}
		}
		return {-1, -1};
    }
};
