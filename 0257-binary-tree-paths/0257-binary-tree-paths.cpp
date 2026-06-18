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
    void f(TreeNode *root,vector<string>&ans,vector<int>&arr){
        if(root==NULL)return ;
        arr.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            string temp="";
            for(int i=0;i<arr.size();i++){
                temp+=to_string(arr[i]);
                if(i!=arr.size()-1){
                    temp+="->";
                }
            }
            ans.push_back(temp);
            arr.pop_back();
            return ;
            
        }
        
        f(root->left,ans,arr);
        
        f(root->right,ans,arr);
        arr.pop_back();

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        vector<int>arr;
        f(root,ans,arr);
        return ans;
        
    }
};