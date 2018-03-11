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
    int maxPathSum(TreeNode *root) {
		int sum = -99999;
		maxsum(root, sum);		
		return sum;
    }
	
	int maxsum(TreeNode *root, int & sum)
	{
		if(!root)return 0;	
		int left = max(maxsum(root->left, sum), 0);
		int right = max(maxsum(root->right, sum), 0);
		sum = max(sum, left + right + root->val);
		return max(left, right) + root->val;
	}
};