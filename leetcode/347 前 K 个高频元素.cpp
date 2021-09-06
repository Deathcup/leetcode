#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
		class cmp {
			public:
				bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
					return lhs.second > rhs.second;
				}
		};
	public:
		vector<int> topKFrequent(vector<int> &nums, int k) {
			unordered_map<int, int> map;
			for (auto num : nums) {
				map[num]++;
			}
			priority_queue < pair<int, int>, vector<pair<int, int> >, cmp> pri_que;
			for (auto iter : map) {
				pri_que.push(pair<int, int>(iter.first, iter.second));
				if (pri_que.size() > k) {
					pri_que.pop();
				}
			}
			vector<int> res;
			while (k--) {
				if (!pri_que.empty()) {
					res.push_back(pri_que.top().first);
					pri_que.pop();
				}
			}
			return res;
		}
};