class Solution {
public:
    int solveTab(vector<int>& days, vector<int>& costs){
        
        vector<int> dp(days.size() +1, INT_MAX);
        dp[days.size()] = 0;
        
        for(int k = days.size() - 1; k >=0; k--){
        int day1 = costs[0] + dp[k + 1];
        
        int i;
        for(i = k ; i< days.size() && days[i] < days[k] + 7; i++);
        
        int day7 = costs[1] + dp[i];
        
        for(i = k ; i< days.size() && days[i] < days[k] +30; i++);
        
        int day30 = costs[2] + dp[i];
        
        dp[k] = min(day1, min(day7, day30));
        }
        return dp[0];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size() +1, -1);
        // return solveMem(days, costs, 0,dp);
        return solveTab(days, costs);
    }
};