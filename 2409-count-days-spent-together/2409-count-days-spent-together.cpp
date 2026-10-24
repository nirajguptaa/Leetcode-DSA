class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
         vector<int>daysInMonths={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto getDays=[&](string date){
            int month=stoi(date.substr(0,2));
            int day=stoi(date.substr(3,2));
            for(int i=0;i<month-1;i++){
                day+=daysInMonths[i];
            }
            return day;
        };
        int a1=getDays(arriveAlice);
        int a2=getDays(leaveAlice);
        int b1=getDays(arriveBob);
        int b2=getDays(leaveBob);

        return max(0, min(a2, b2) - max(a1, b1) + 1);

    }
};