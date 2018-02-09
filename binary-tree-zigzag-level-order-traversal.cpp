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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > res;
		vector<int> cur;
		if(!root)return res;
		bool nowflag =0;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty())
		{
			int n = q.size();
			cur.clear();
			for(int i = 0;i < n; ++i)
			{
				TreeNode* b = q.front();
				q.pop();
				cur.push_back(b->val);
				if(b->left)
				  q.push(b->left);
				if(b->right)
				  q.push(b->right);
			}
			
			if(res.size()%2 == 0)
				res.push_back(cur);
			else
			{
				reverse(cur.begin(), cur.end());
				res.push_back(cur);					
				
			}
				
		}	
		return res;
    }	
};