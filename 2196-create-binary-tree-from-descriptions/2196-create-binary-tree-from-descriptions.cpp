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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>childNodes;
        for(auto it: descriptions){
            int par=it[0];
            int child=it[1];
            int isLeft=it[2];
            
            if(mp.find(par)==mp.end()){
                mp[par]=new TreeNode(par);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(isLeft){
                mp[par]->left=mp[child];
            }else{
                mp[par]->right=mp[child];
            }
            childNodes.insert(child);
        }
        for(auto &it:mp){
            if(childNodes.find(it.first)==childNodes.end()){
                return it.second;
            }
            
        }
        return nullptr;
    
    }
};