/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *build(vector<int>&preorder,int pS,int pE,vector<int>&inorder,int iS,int iE,unordered_map<int,int>&mp){
        if(pS>pE || iS>iE)return NULL;
        TreeNode *root=new TreeNode(preorder[pS]);
        int idx=mp[root->val];
        int numsLeft=idx-iS;
        root->left=build(preorder,pS+1,pS+numsLeft,inorder,iS,iS+numsLeft,mp);
        root->right=build(preorder,pS+numsLeft+1,pE,inorder,iS+numsLeft+1,iE,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,0,n-1,inorder,0,n-1,mp);
        return root;
        
    }
};