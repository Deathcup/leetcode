class Solution {
public:
    bool isValid(string s) {
		stack<char> sta;
		for (auto c: s){
			if (c == '{' || c == '[' || c == '(' ){
				sta.push(c);
			}
			if (c == '}' || c == ']' || c == ')'){
				if (sta.empty()) return 0;
				char t = sta.top();
				if ((t == '{' && c == '}') || (t == '(' && c == ')' ) || (t == '[' && c == ']')){
					sta.pop();
				}
				else{
					return 0;
				}
			}
		}
		if (sta.empty()) return 1;
		else return 0;
    }
};
