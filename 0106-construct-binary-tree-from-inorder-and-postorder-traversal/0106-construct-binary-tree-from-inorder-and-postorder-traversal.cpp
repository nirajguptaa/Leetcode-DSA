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
    TreeNode *build(vector<int>&inorder,int iS,int iE,vector<int>&postorder,int pS,int pE,unordered_map<int,int>&mp){
        if(iS>iE || pS>pE){
            return NULL;
        }
        TreeNode *root=new TreeNode(postorder[pE]);
        int idx=mp[root->val];
        int numsLeft=idx-iS;
        root->left=build(inorder,iS,idx-1,postorder,pS,pS+numsLeft-1,mp);
        root->right=build(inorder,idx+1,iE,postorder,pS+numsLeft,pE-1,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode *root=build(inorder,0,n-1,postorder,0,n-1,mp);
        return root;
    }
};