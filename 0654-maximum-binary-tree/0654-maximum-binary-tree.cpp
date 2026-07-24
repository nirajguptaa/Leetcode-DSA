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
    TreeNode *buildTree(int start,int end,vector<int>&nums){
        if(start<0 || start>end || end>nums.size()){
            return NULL;
        }
        int maxi=-1;
        for(int i=start;i<=end;i++){
            maxi=max(maxi,nums[i]);
        }
        int idx=-1;
        for(int i=start;i<=end;i++){
            if(maxi==nums[i]){
                idx=i;
            }
        }
        if(idx==-1){
            return NULL;
        }
        TreeNode *node=new TreeNode(maxi);
        node->left=buildTree(start,idx-1,nums);
        node->right=buildTree(idx+1,end,nums);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(0,nums.size()-1,nums);
    }
};