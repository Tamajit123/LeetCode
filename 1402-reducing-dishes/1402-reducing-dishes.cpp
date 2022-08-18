class Solution {
public:
    int solveMem(vector<int>& satisfaction,int index, int time,vector<vector<int>> &dp){
        int n = satisfaction.size();
        //Base Case
        
        if(index == satisfaction.size())
            return 0;
        
        
        if(dp[index][time] != -1)
            return dp[index][time];
        
        
        int incld = satisfaction[index]*(time+1) + solveMem(satisfaction,index+1, time + 1,dp); 
        int excld = 0+ solveMem(satisfaction,index+1, time,dp);
        dp[index][time] = max(incld, excld);
        
        return dp[index][time];
    }
    int solveTab(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
        for(int index= n-1; index>=0; index-- ){
            for(int time = index; time >=0 ; time --){
                int incld = satisfaction[index]*(time+1) + dp[index+1][time + 1]; 
                int excld = 0+ dp[index+1][time];
                dp[index][time] = max(incld, excld);
            }
        }
        return dp[0][0]  ;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin() , satisfaction.end());
        
        int n = satisfaction.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solveMem(satisfaction,0,0,dp);
        
        return solveTab(satisfaction);
    }
};