/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode*root,string &tree){
        if(root==NULL){
            tree+="#,";
            return ;
        }
        tree+=to_string(root->val)+",";
        preorder(root->left,tree);
        preorder(root->right,tree);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree;
        preorder(root,tree);
        return tree;
    }
    TreeNode *depreorder(queue<string>&q){
        if(q.empty())return nullptr;
        string val=q.front();
        q.pop();
        if(val=="#"){return NULL;}
        TreeNode *root=new TreeNode(stoi(val));
        root->left=depreorder(q);
        root->right=depreorder(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            q.push(token);
        }
        return depreorder(q);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));