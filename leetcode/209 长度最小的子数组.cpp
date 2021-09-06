class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = nums[0];
        int i = 1;
        int j = 0;
        while (i < nums.size() || j < nums.size()){
			if (sum < target){
				if (i >= nums.size()){
					sum -= nums[j];
					j++;
				}
				else{
	        		sum += nums[i];
					i++;					
				}

        	}
        	else {
        		if (i - j < ans){
        			ans = i - j;
        		}
        		sum -= nums[j];
        		j++;
        	}
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

//方法2 差分 + 二分 
class Solution {
public:
	bool check(vector<int>& nums, int ans, int target){
		int sum;
		for (int i = 0; i < nums.size(); i++){
			if (i + ans - 1 >= nums.size()) break;
			if (i == 0){
				sum = nums[i + ans - 1];
			} 
			else {
				sum = nums[i + ans - 1] - nums[i-1];
			}
			if (sum >= target) return 1;
		}
		return 0;
	}
    int minSubArrayLen(int target, vector<int>& nums) {
         for (int i = 1; i < nums.size(); i++){
         	nums[i] += nums[i-1];
         }
         if (nums[nums.size()-1] < target) return 0;
         int left = 0;
         int right = nums.size();
         int middle;
         while (left <= right){
         	middle = left + ((right - left) >> 1);
         	//cout<<middle<<" "<<check(nums,middle,target)<<endl;
         	if (check(nums,middle,target)){
         		right = right - 1;
         	}
         	else{
         		left = left + 1;
         	}
         }
         return left;
    }
};
 
