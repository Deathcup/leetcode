#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r){
        	mid = l + ((r-l)/2);
        	if (nums[mid] > target) r=mid-1;
        	else if(nums[mid] < target) l=mid+1;
        	else return mid;
        }
        return -1;
    }
};

int main(){
	int a[] = {-1, 0, 3, 5, 9, 12};
	int target = 9;
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	Solution solution;
	cout << solution.search(nums, target) << endl;
}
