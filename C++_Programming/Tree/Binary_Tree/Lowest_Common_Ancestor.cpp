#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val=x;
        left=right=NULL;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        TreeNode *lca1=lowestCommonAncestor(root->left,p,q);
        TreeNode *lca2=lowestCommonAncestor(root->right,p,q);
        if(lca1!=NULL && lca2!=NULL) return root;
        else if(lca1!=NULL) return lca1;
        else return lca2;
        return NULL;
    }

int main()
{
    
    return 0;
}