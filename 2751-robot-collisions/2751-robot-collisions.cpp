class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>idx(n);
        for(int i=0;i<n;i++){
            idx[i]=i;
        }
        sort(idx.begin(),idx.end(),[&](int a,int b){
            return positions[a]<positions[b];
        });
        stack<int>s;
        for(int id:idx){
            if(directions[id]=='R'){
                s.push(id);
            }else{

                while(!s.empty() && healths[id]>0){
                    int topIdx=s.top();
                    s.pop();
                    if(healths[topIdx]>healths[id]){
                        healths[topIdx]--;
                        healths[id]=0;
                        s.push(topIdx);
                    }else if(healths[topIdx]<healths[id]){
                        healths[id]--;
                        healths[topIdx]=0;
                        
                    }else{
                        healths[id]=0;
                        healths[topIdx]=0;
                        
                    }

                }
                
            }
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }
        
        return ans;
    }
};