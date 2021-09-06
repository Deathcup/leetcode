class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> set;
		unordered_set<int> res;
		vector<int> a;
		for (auto i:nums1){
			set.insert(i);
		}
		for (auto i:nums2){
			if (set.count(i)){
				res.insert(i);
			}
		}
		a.assign(res.begin(),res.end());
		return a;
    }
};
