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
    int sumNumbers(TreeNode *root) {
		if(root == NULL)return 0;
		int sum = 0, temp = 0;
		
		sumNumber(root, sum, temp);
		return sum;
    }
	
	void sumNumber(TreeNode *root, int &sum, int &temp){
		if(root->left == NULL and root->right == NULL)
		{
			sum += temp * 10 + root->val;
			return;
		}		
		temp = temp * 10 + root->val;
		if(root->left)
			sumNumber(root->left, sum, temp);
		if(root->right)
			sumNumber(root->right, sum, temp);
		temp = (temp - root->val)/10;
	}

};