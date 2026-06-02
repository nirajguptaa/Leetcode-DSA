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
    unordered_map<long long,int>mp;
    int count=0;
    void dfs(TreeNode *root,int targetSum,long long currSum){
        if(root==NULL)return;
        currSum+=root->val;
        count+=mp[currSum-targetSum];
        mp[currSum]++;
        dfs(root->left,targetSum,currSum);
        dfs(root->right,targetSum,currSum);
        mp[currSum]--;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        dfs(root,targetSum,0);
        return count;
    }
};