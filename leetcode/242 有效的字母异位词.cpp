class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> sset;
        multiset<char> tset;
        for(auto c : s){
        	sset.insert(c);
        }
        for(auto c : t){
        	tset.insert(c);
        }
        if (sset == tset){
        	return 1;
        }
        else return 0;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        for (auto c : s){
        	map[c]++;
        }
        for (auto c : t){
        	map[c]--;
        }
        for (auto iter = map.begin(); iter != map.end();){
        	if (iter->second == 0){
        		map.erase(iter++);
        	}
        	else{
        		iter++;
        	}
        }
        if (map.empty()){
        	return 1;
        }
        else return 0;
    }
};
