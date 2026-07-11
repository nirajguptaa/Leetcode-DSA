class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int>mp;
        for(auto it:friends){
            mp.insert(it);
        }
        vector<int>anns;
        for(int x:order){
            if(mp.count(x)){
                anns.push_back(x);
            }
        }
        return anns;
    }
};