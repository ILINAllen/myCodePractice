class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode)
            return NULL;
        if(pNode->right) {
            pNode = pNode->right;
            while(pNode->left)
                pNode = pNode->left;
            return pNode;
        }
        auto p = pNode->next;
        while(p&&pNode==p->right) {
            pNode = p;
            p = pNode->next;
        }
        return p; 
    }
};