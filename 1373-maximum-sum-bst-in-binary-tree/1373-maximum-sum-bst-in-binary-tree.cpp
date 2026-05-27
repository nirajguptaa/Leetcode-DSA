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
    int maxsum=0;
    struct Info{
        bool isBst;
        int minVal;
        int maxVal;
        int sum;
    };
    Info solve(TreeNode* root){
        if(root==NULL ){
            return {true,INT_MAX,INT_MIN,0};
        }
        Info left=solve(root->left);
        Info right=solve(root->right);
        if(left.isBst && right.isBst && root->val>=left.maxVal && root->val<right.minVal){
            int currsum=root->val+left.sum+right.sum;
            maxsum=max(maxsum,currsum);
            return {true,min(root->val,left.minVal),max(root->val,right.maxVal),currsum};
        }
        return {false,0,0,0};
            
    }
    int maxSumBST(TreeNode* root) {
        
        solve(root);
        return max(maxsum,0);

    }
};