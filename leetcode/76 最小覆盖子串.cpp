class Solution {
public:
	
	bool check(unordered_map<char, int> map, string t){
		for (int i = 0; i < t.size(); i++){
			if(map.find(t[i]) != map.end()){
				if(map[t[i]] < 0) return 0;
			}
		}
		return 1;
	}
    string minWindow(string s, string t) {
    	if(t.size() > s.size()) return "";
    	int ans = INT_MAX,l = 0,r = 0;
        unordered_map<char,int> map;
        for (int i = 0; i < s.size(); i++){
        	map[t[i]]--;
        }
        int j = 0;
		for (int i = 0; i < s.size(); i++){
			if (i < s.size())	map[s[i]]++;
			while (check(map,t)){
				if (i-j+1 < ans){
					ans = i-j+1;
					l=j;
					r=i;
				}
				if (j < s.size())	map[s[j]]--;
				j++;
			}
		}
		if (ans == INT_MAX) return "";
		//return string(s.begin() + l, s.begin() + r + 1);
		return s.substr(l,r);
    }
};
