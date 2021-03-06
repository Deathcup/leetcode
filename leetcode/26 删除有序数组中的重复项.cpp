class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int index = 1;
		if (nums.size() == 0) return 0;
		for (int i = 1; i < nums.size(); i++){
			if(nums[i] == nums[i-1]) continue;
			nums[index++] = nums[i];
		}
		return index;
    }
};
