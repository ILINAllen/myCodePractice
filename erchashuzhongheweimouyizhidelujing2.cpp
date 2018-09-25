class Solution {
    void TreePath(TreeNode* root,int target,vector<int> &path,vector<vector<int> > &pathList)
    {
        if(root == NULL)
            return ;
        path.push_back(root->val);
        bool isLeaf = root->left==NULL && root->right==NULL;
        if(root->val==target && isLeaf)
        {
            pathList.push_back(path);
            path.pop_back();
        }
        else
        {
            TreePath(root->left,target - root->val,path,pathList);
            TreePath(root->right,target - root->val,path,pathList);
            path.pop_back();
        }
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber)
    {
        vector<vector<int> > FindPath;
        vector<int> Path;  // 为了保存每一次递归的值,这里声明了一个path
        if(root == NULL)
            return FindPath;
        TreePath(root,expectNumber,Path,FindPath);
        return FindPath;
    }
};