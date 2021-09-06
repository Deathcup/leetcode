/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
	public:
		void traversal(TreeNode *cur, vector<int> &vec) {
			if (cur == nullptr)
				return;
			vec.push_back(cur->val);
			traversal(cur->left, vec);
			traversal(cur->right, vec);
		}
		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> res;
			traversal(root, res);
			return res;
		}
};

class Solution {
	public:
		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> res;
			stack<TreeNode *> sta;
			if (root == nullptr)
				return res;
			sta.push(root);
			while (!sta.empty()) {
				TreeNode *cur = sta.top();
				sta.pop();
				if (cur != nullptr) {
					if (cur->right)
						sta.push(cur->right);
					if (cur->left)
						sta.push(cur->left);
					sta.push(cur);
					sta.push(nullptr);
				} else {
					cur = sta.top();
					sta.pop();
					res.push_back(cur->val);
				}
			}
			return res;
		}
};