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
    void f(long long currSum,TreeNode*root,int target){
        if(root==NULL)return ;
        currSum+=root->val;
        count+=mp[currSum-target];
        mp[currSum]++;
        f(currSum,root->left,target);
        f(currSum,root->right,target);
        mp[currSum]--;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        f(0,root,targetSum);
        return count;
    }
};