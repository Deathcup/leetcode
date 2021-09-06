#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while (left <= right){
        	middle = left + ((right - left) >> 1);
        	if (nums[middle] > target){
        		right = middle - 1;
        	}
        	else if (nums[middle] < target){
        		left = middle + 1;
        	}
        	else {
        		return middle;
        	}
        }
        return left;
    }
};

int main(){
	int a[] = {-1, 0, 3, 5, 9, 12};
	int target = 9;
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	Solution solution;
	cout << solution.searchInsert(nums, target) << endl;
}
