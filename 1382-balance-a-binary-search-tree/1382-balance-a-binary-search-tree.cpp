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
    void inorder(TreeNode* root,vector<int>&arr){
        if(root==NULL)return ;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balancedTree(vector<int>&arr,int l,int h){
        if(l>h)return NULL;
        int mid=l+(h-l)/2;
        TreeNode *node=new TreeNode(arr[mid]);
        node->left=balancedTree(arr,l,mid-1);
        node->right=balancedTree(arr,mid+1,h); 
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        return balancedTree(arr,0,arr.size()-1);
    }
};