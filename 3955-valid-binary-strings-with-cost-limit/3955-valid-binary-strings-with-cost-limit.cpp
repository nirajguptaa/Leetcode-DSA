class Solution {
public:
    bool valid(string bin,int k){
        
        int len=bin.size();
        bool cond1=true;
        int cost=0;
        for(int i=1;i<len;i++){
            if(bin[i]=='1' && bin[i-1]=='1'){
                cond1=false;
            }
              
        }
        for(int i=0;i<len;i++){
            if(bin[i]=='1'){
                cost+=i;
            }
        }
        
        return cond1 && cost<=k;
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        int poss=1<<n;
        for(int i=0;i<poss;i++){
            string bin=bitset<12>(i).to_string();
            bin=bin.substr(12-n);
            if(valid(bin,k)){
                ans.push_back(bin);
            }
        }
        return ans;
    }
};