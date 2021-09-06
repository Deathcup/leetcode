class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n,0));
		int round = 0;
		int tot_round = n/2;
		int count = 0;
		while (round <= tot_round){
			if (n == 1){
				res[round][round] = ++count;
			}
			for (int i = round; i <= round + n - 2; i++){
				res[round][i] = ++count;
			}
			for (int i = round; i <= round + n - 2; i++){
				res[i][round + n - 1] = ++count;
			}
			for (int i = round + n - 1; i >= round + 1; i--){
				res[round + n - 1][i] = ++count;
			}
			for (int i = round + n - 1; i >= round + 1; i--){
				res[i][round] = ++count;
			}
			round++;
			n -= 2;
		}
		return res;
    }
};
