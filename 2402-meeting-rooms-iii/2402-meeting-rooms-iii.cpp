class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int>freq(n,0);
        priority_queue<int,vector<int>,greater<int>>freeRooms;
        for(int i=0;i<n;i++){
            freeRooms.push(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>>busyRooms;
        // endTime room
        
        for(auto m:meetings){
            int start=m[0];
            int end=m[1];
            while(!busyRooms.empty() && busyRooms.top().first<=start){
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            if(!freeRooms.empty()){
                int room=freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end,room});
                freq[room]++;
            }else{
                auto [finish,room]=busyRooms.top();
                busyRooms.pop();
                busyRooms.push({finish+(end-start),room});
                freq[room]++;
            }
            
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(freq[i]>freq[ans]){
                ans=i;
            }
        }
        return ans;
    }
};