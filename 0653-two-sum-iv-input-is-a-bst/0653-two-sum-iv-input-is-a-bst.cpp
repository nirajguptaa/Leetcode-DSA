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
    bool findTar(TreeNode* root, int k,unordered_set<int>&mp){
        if(root==NULL)return false;
        int curr=root->val;
        int remain=k-curr;
        if(mp.find(remain)!=mp.end()){
            return true;
        }
        mp.insert(curr);
        return findTar(root->left,k,mp)||findTar(root->right,k,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>mp;
        return findTar(root,k,mp);
        
    }

};