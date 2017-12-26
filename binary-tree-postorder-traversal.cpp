/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
		
	void postorder(vector<int>& vec, TreeNode *root)
	{
		if(root == NULL)return;
		postorder(vec, root->left);
		postorder(vec, root->right);
		vec.push_back(root->val);
	}

    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> vec;
		postorder(vec, root);
		return vec;
    }
};