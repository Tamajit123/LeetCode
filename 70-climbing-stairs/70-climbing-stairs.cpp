#define vi vector<int>
class Solution {
public:
    int solveMem(int n,vector<int>&dp){
       if(n<= 1)
           return dp[n] = 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        
        dp[n] = solveMem(n-1,dp) + solveMem(n-2,dp);
        return dp[n];
    }
    int solveTab(int n){
        vi dp(n+1,0);
        
        for(int i = 0; i<=n; i++){
            if(i<= 1){
                dp[i] = 1;
                continue;
            }
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // return solveMem(n,dp);
        return solveTab(n);
    }
};