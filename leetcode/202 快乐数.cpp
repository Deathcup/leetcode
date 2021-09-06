class Solution {
public:
    bool isHappy(int n) {
		unordered_set<int> set;
		while (n != 1){
			int newNum = 0;
			while (n>9){
				int t = n%10;
				newNum += t*t;
				n = n/10;
			}
			newNum += n*n;
			if (set.count(newNum)) return 0;
			set.insert(newNum);
			n = newNum;
		}
		return 1;
    }
};
