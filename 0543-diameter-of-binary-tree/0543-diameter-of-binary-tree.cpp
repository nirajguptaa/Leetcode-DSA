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
    
    int f(TreeNode *root,int &maxD){
        if(root==NULL)return 0;
        int left=f(root->left,maxD);
        int right=f(root->right,maxD);
        maxD=max(maxD,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int maxD=0;
        f(root,maxD);
        return maxD;

    }
};