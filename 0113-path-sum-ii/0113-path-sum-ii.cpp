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
    void f(int curr,TreeNode *root,int targetSum,vector<int>&temp,vector<vector<int>>&ans){
        if(root==NULL)return ;
        curr+=root->val;
        temp.push_back(root->val);
        if(curr==targetSum && root->left==NULL && root->right==NULL){
            ans.push_back(temp);
            
        }
        
        f(curr,root->left,targetSum,temp,ans);
        f(curr,root->right,targetSum,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,root,targetSum,temp,ans);
        return ans;
    }
};