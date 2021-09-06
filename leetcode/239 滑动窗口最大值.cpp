class Solution {
	public:
		class MyQueue {
			public:
				deque<int> que;

				void push(int x) {
					while (!que.empty() && x > que.back()) {
						que.pop_back();
					}
					que.push_back(x);
				}

				void pop(int x) {
					if (!que.empty() && x == que.front()) {
						que.pop_front();
					}
				}

				int front() {
					return que.front();
				}
		};
		vector<int> maxSlidingWindow(vector<int> &nums, int k) {
			MyQueue que;
			vector<int> res;
			for (int i = 0; i < k; i++) {
				que.push(nums[i]);
			}
			res.push_back(que.front());
			int j = 0;
			for (int i = k; i < nums.size(); i++) {
				que.pop(nums[j]);
				j++;
				que.push(nums[i]);
				res.push_back(que.front());
			}
			return res;
		}
};

