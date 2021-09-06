#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

class Solution {
	public:
		int evalRPN(vector<string> &tokens) {
			stack<int> sta;
			for (auto i : tokens) {
				if (i == "+" || i == "-" || i == "*" || i == "/") {
					int a = sta.top();
					sta.pop();
					int b = sta.top();
					sta.pop();
					//cout<<a<<" "<<b<<endl;
					if (i == "+")
						sta.push(a + b);
					if (i == "-")
						sta.push(b - a);
					if (i == "*")
						sta.push(a * b);
					if (i == "/")
						sta.push(b / a);
				} else {
					sta.push( stoi(i));
				}
			}
			return sta.top();
		}
};

int main() {
	vector<string> tokens = {"4", "13", "5", "/", "+"};
	Solution solution;
	cout << solution.evalRPN(tokens) << endl;
	return 0;
}


