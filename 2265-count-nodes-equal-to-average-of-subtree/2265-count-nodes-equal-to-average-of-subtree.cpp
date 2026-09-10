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
       int nodes(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int total=0;
        total++;
        total+=nodes(root->left);
        total+=nodes(root->right);
        return total;

    }
    int sum(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        int total=0;
        total+=root->val;
        total+=sum(root->left);
        total+=sum(root->right);
        return total;

    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int count=0;
        if(sum(root)/nodes(root)==root->val){
            count++;
        }
        count+=averageOfSubtree(root->left);
        count+=averageOfSubtree(root->right);
        return count;
    }
};