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
    int dfs(TreeNode* root,string &str){
        if(!root)return 0;
        str.push_back(root->val+'0');
        int sum=0;
        if(!root->left && !root->right){
            sum=stoi(str,nullptr,2);
        }else{
            sum+=dfs(root->left,str);
            sum+=dfs(root->right,str);
        }
        str.pop_back();
        return sum;
    }
    int sumRootToLeaf(TreeNode* root) {
       string str="";
        return dfs(root,str);
    
    }
};