class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> res;
    	if(matrix.empty()) return res;
		int count = 0;
		int n = matrix.size(), m = matrix[0].size();
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};
		int x = 0, y = 0;
		int state = 0;
		while (count < n*m){
			res.push_back(matrix[x][y]);
			matrix[x][y] = INT_MAX;
			count++;
			if (x + dx[state] >= n || x + dx[state] < 0 || y + dy[state] >=m || y + dy[state] < 0){
				state++;
				state = state % 4;
			} 
			else if (matrix[x + dx[state]][y + dy[state]] == INT_MAX){
				state++;
				state = state % 4;
			}
			x = x + dx[state];
			y = y + dy[state];
		}
		return res;
    }
};
