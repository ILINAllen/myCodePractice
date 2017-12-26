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
	void preorder(vector<int> &vec, TreeNode *root)
	{
		if(root == NULL)return;
		vec.push_back(root->val);
		preorder(vec, root->left);
		preorder(vec, root->right);
		
	}


    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> vec;
		preorder(vec, root);
		return vec;
    
    }
};