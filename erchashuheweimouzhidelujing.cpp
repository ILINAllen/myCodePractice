/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
     void FindPathSum(TreeNode* root,int expectNumber,vector<int >&vec, vector<vector<int> >&res)
	 {
		 if(root==NULL)
		 {
			return;
	     }
		 vec.push_back(root->val);
		 bool isend=root->left==NULL&&root->right==NULL; //刚好遍历结束，是尾节点
		 if(root->val==expectNumber&&isend)             //深度到底，而且和为整个路径
		 {
			 res.push_back(vec);
			 vec.pop_back();			 
		 }	 
		 else                   //没到底部，或者和不为target
		 {
			 FindPathSum(root->left,expectNumber-root->val,vec,res);
			 FindPathSum(root->right,expectNumber-root->val,vec,res);
			 vec.pop_back();	
		 }
	 }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {  
	 vector<int >vec;
	 vector<vector<int> >res;
	  if(root==NULL)return res;
	  FindPathSum(root,expectNumber,vec,res);
	  return res;
    }	
};