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
    void preorder(TreeNode* root,string &tree){
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

    TreeNode *depreorder(queue<string>&nodes){
        if(nodes.empty()){
            return nullptr;
        }
        string val=nodes.front();
        nodes.pop();
        if(val=="#")return NULL;
        TreeNode *root=new TreeNode(stoi(val));
        root->left=depreorder(nodes);
        root->right=depreorder(nodes);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>nodes;
        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            nodes.push(token);
        }
        return depreorder(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));