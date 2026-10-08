class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>pos;

    RandomizedSet() {
    }
        
    
    bool insert(int val) {
        if(pos.count(val)){
            return false;
        }
        int size=nums.size();
        pos[val]=size;
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!pos.count(val)){
            return false;
        }
        int last=nums.back();//ele
        int idx=pos[val];

        nums[idx]=last;
        pos[last]=idx;
        nums.pop_back();
        pos.erase(val);
        return true;

    }
    
    int getRandom() {
        int idx=rand() % nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */