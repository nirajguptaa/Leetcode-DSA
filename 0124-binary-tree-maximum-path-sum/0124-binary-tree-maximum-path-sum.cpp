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
    
    int calSum(int &currSum,TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int left=max(0,calSum(currSum,root->left));
        int right=max(0,calSum(currSum,root->right));
        currSum=max(currSum,left+right+root->val);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        calSum(sum,root);
        return sum;
    }
};