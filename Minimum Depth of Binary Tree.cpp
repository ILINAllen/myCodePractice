class Solution {
public:
	int min(int a, int b)
	{ return a < b ? a : b;}

	int run(TreeNode *root) {
		
		if(root == null)
			return 0;
		int l = run(root->left);
		int r = run(root->right);
		if(r==0||l==0)
			return 1 + r + l;
		else
			return 1 + min(r, l);
		
		
    }
};