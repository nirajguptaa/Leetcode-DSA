/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void addParent(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==NULL){
            return;
        }
        if(root->left){
            parent[root->left]=root;
            addParent(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            addParent(root->right,parent);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root]=root;
        addParent(root,parent);
        queue<TreeNode*>q;
        unordered_set<TreeNode*>vis;
        q.push(target);
        vis.insert(target);
        while(!q.empty() && k>0){
            int size=q.size();
            k--;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();

                if(node->left&& vis.find(node->left)==vis.end()){
                    q.push(node->left);
                    vis.insert(node->left);
                    
                }
                if(node->right && vis.find(node->right)==vis.end()){
                    vis.insert(node->right);
                    q.push(node->right);
                }
                if(parent[node]!=node && vis.find(parent[node])==vis.end()){
                    q.push(parent[node]);   
                    vis.insert(parent[node]);

                }
            }

        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};