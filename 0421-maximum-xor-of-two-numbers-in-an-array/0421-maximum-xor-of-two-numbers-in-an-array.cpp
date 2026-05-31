struct Node{
    Node *links[2]={nullptr,nullptr};
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void set(int bit,Node *node){
        links[bit]=node;
    }
};
class Solution {
public:
    Node *root;
    Solution(){
        root=new Node();
    }
    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!(node->containsKey(bit))){
                node->set(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node *node=root;
        int maxVal=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(node->containsKey(1-bit)){
                maxVal=maxVal|(1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxVal;
    }
    int findMaximumXOR(vector<int>& nums) {

        for(int num:nums){
            insert(num);
        }
        int maxVal=0;
        for(int num:nums){
            maxVal=max(maxVal,getMax(num));
        }
        return maxVal;
    }
};