class Solution {
public:
    string removeDuplicates(string s) {
		stack<int> sta;
		for (auto c : s){
			if (!sta.empty() && sta.top() == c){
				sta.pop();	
			}
			else{
				sta.push(c);
			}
		}
		if (sta.empty()) return "";
		vector<char> res(sta.size());
		int k = res.size() -1;
		while(!sta.empty()){
			res[k--] = sta.top();
			sta.pop();
		}
		return string(res.begin(), res.end());
    }
};
