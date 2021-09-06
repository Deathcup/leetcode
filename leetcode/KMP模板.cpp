class Solution {
public:
	vector<int> getNext(string s){
		vector<int> next(s.size());
		int j = 0;
		next[j] = 0;
		for (int i = 1; i < s.size(); i++){
			while (j > 0 && s[i] != s[j]){
				j = next[j-1];
			}
			if (s[i] == s[j]){
				j++;
			}
			next[i] = j;
		}
		return next;
	}
	
    int strStr(string haystack, string needle) {
    	if (needle.size() == 0) return 0;
		vector<int> next = getNext(needle);
		int j = 0;
		for (int i = 0; i < haystack.size(); i++){
			while (j > 0 && haystack[i] != needle[j]){
				j = next[j-1];
			}
			if (haystack[i] == needle[j]){
				j++;
			}
			if (j == needle.size()){
				return i-j+1;
			}
		}
		return -1;
    }
};
