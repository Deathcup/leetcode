class Solution {
public:
    int totalFruit(vector<int>& fruits) {
		unordered_map<int,int> basket;
		int first = 0;
		int end = 0;
		int ans = 0;
		while ( end < fruits.size()){
			basket[fruits[end]]++;
			end++;
			while (basket.size() > 2){
				basket[fruits[first]]--;
				if(basket[fruits[first]] == 0) basket.erase(fruits[first]);
				first++;
			}
			if (end - first > ans){
				ans = end - first;
			}
		}
		return ans;
    }
};
