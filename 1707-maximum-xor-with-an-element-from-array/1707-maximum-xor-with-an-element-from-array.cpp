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
        for(int i=31;i>=0;i--){//32*n
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
        for(int i=31;i>=0;i--){//time = 32 *n 
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int q=queries.size();
        vector<pair<int,pair<int,int>>>qQ;
        for(int i=0;i<q;i++){
            qQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(qQ.begin(),qQ.end());
        vector<int>res(q,0);
        int j=0;
        for(int i=0;i<q;i++){
            int mi=qQ[i].first;
            int xi=qQ[i].second.first;
            int idx=qQ[i].second.second;
            while(j<nums.size() && nums[j]<=mi){
                insert(nums[j]);
                j++;
            }
            if(j==0){
                res[idx]=-1;
            }else{
                res[idx]=getMax(xi);
            }
        }
        return res;

       
    }
};