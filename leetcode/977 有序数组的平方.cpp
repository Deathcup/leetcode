class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
		int first = 0;
		int end = nums.size() - 1;
		int cnt = nums.size() - 1;
		vector<int> a(nums.size(),0);
		while (first <= end){
			if ( abs(nums[first]) > abs (nums[end])){
				a[cnt--] = nums[first] * nums[first];
				first++;
			}
			else {
				a[cnt--] = nums[end] * nums[end]; 
				end--;
			}
		}
		return a;
    }
};
