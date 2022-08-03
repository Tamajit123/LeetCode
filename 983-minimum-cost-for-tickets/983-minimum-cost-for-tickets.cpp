class Solution {
public:
    int solveMem(vector<int>& days, vector<int>& costs, int index,vector<int> &dp){
        if(index >= days.size())
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        
        int day1 = costs[0] + solveMem(days, costs, index + 1,dp);
        
        int i;
        for(i = index ; i< days.size() && days[i] < days[index] + 7; i++);
        
        int day7 = costs[1] + solveMem(days, costs, i,dp);
        
        for(i = index ; i< days.size() && days[i] < days[index] +30; i++);
        
        int day30 = costs[2] + solveMem(days, costs, i,dp);
        
        dp[index] = min(day1, min(day7, day30));
        return dp[index];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() +1, -1);
        return solveMem(days, costs, 0,dp);
        
    }
};