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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=preorder.size()-1;
        TreeNode *root=build(preorder,0,n,inorder,0,n,mp);   
        return root;
    }
    TreeNode *build(vector<int>& preorder,int pS,int pE ,vector<int>& inorder,int iS,int iE,unordered_map<int,int>&mp){
        if(pS>pE || iS>iE)return NULL;
        TreeNode *node=new TreeNode(preorder[pS]);
        int inRoot=mp[node->val];
        int numsLeft=inRoot-iS;
        node->left=build(preorder,pS+1,pS+numsLeft,inorder,iS,iS+numsLeft,mp);
        node->right=build(preorder,pS+numsLeft+1,pE,inorder,iS+numsLeft+1,iE,mp);
        return node;
    }
};