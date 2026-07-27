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
    TreeNode *constructTree(int preStart,int preEnd,vector<int>& preorder,int postStart,int postEnd,vector<int>& postorder,unordered_map<int,int>&mp){
        if(preStart>preEnd || postStart>postEnd){
            return NULL;
        }
        TreeNode *node=new TreeNode(preorder[preStart]);
        if(preStart==preEnd){
            return node;
        }
        int idx=mp[preorder[preStart+1]];
        int leftsize=idx-postStart+1;
        node->left=constructTree(preStart+1,preStart+leftsize,preorder,postStart,idx,postorder,mp);
        node->right=constructTree(preStart+leftsize+1,preEnd,preorder,idx+1,postEnd-1,postorder,mp);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]]=i;
        }

        TreeNode *node=constructTree(0,preorder.size()-1,preorder,0,postorder.size()-1,postorder,mp);
        return node;
    }
};