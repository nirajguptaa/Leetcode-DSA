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
    // bool isBST(TreeNode *root,long minval=LONG_MIN,long maxval=LONG_MAX){
    //     if(root==NULL)return true;
        
    //     if(root->val<=minval || root->val>maxval)return false;
    //     return isBST(root->left,minval,root->val) && isBST(root->right,root->val,maxval);
    // }

    // int  sum(TreeNode* root){
    //     if(root==NULL)return 0;
    //     return sum(root->left)+root->val+sum(root->right);
    // }

    int maxSum=0;
    struct Info{
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };
    Info helper(TreeNode *root){
        if(root==NULL)return {true,INT_MAX,INT_MIN,0};
        Info left=helper(root->left);
        Info right=helper(root->right);
        if(left.isBST && right.isBST  && root->val >= left.maxVal && root->val < right.minVal){
            int currSum=left.sum+root->val+right.sum;
            maxSum=max(maxSum,currSum);
            return {true,min(root->val,left.minVal),max(root->val,right.maxVal),currSum};
        }
        return {false,0,0,0};
    }    
    int maxSumBST(TreeNode* root) {

        helper(root);
        return max(maxSum,0); 

        // if(root==NULL)return 0;
        // int currentsum=0;
        // if(isBST(root)){
        //     currentsum= sum(root);
        // }
        // int leftSum=maxSumBST(root->left);
        // int rightSum=maxSumBST(root->right);
        // int maxRes=max({currentsum,leftSum,rightSum});
        // return max(maxRes,0);
    }
};