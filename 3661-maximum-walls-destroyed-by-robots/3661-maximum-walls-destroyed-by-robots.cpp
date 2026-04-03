class Solution {
public:
    int countWalls(int l,int r,vector<int>& walls){
        int left=lower_bound(walls.begin(),walls.end(),l)-walls.begin();
        int right=upper_bound(walls.begin(),walls.end(),r)-walls.begin();
        return right-left;
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        vector<pair<int,int>>rob;
        for(int i=0;i<robots.size();i++){
            rob.push_back({robots[i],distance[i]});
        }
        int n=rob.size();
        sort(rob.begin(),rob.end());
        sort(walls.begin(), walls.end());
        
        vector<int> left(n), right(n), num(n);

        for(int i=0;i<n;i++){
            int pos=rob[i].first;
            int dist=rob[i].second;
            int l=pos-dist;
            if(i>0){
                l=max(l,rob[i-1].first+1);
            }
            left[i]=countWalls(l,pos,walls);
            
            int r=pos+dist;

            if(i<n-1){
                r=min(r,rob[i+1].first-1);
            }
            right[i]=countWalls(pos,r,walls);
            if(i>0){
                num[i]=countWalls(rob[i-1].first,rob[i].first,walls);
            }
        }
        int prevLeft=left[0];//if shot left
        int prevRight=right[0];//if shot right
        for(int i=1;i<n;i++){
            int currLeft=max(prevLeft+left[i],
            prevRight-right[i-1]+min(left[i]+right[i-1],num[i])
            );
            int currRight=max(prevLeft+right[i],prevRight+right[i]);
            prevRight=currRight;
            prevLeft=currLeft;
        }
            

        return max(prevRight,prevLeft);
        
    }
    
};