class Solution {
public:
    int solveMem(vector<int>& obstacles,int currlane, int curPos,vector<vector<int>> &dp){
        int n = obstacles.size() - 1;
        
        //Base Case
        if(curPos == n)
            return 0;
        
        if(dp[currlane][curPos] != -1){
            return dp[currlane][curPos];
        }
        
        if(obstacles[curPos + 1] != currlane)
        {
            return solveMem(obstacles, currlane, curPos + 1,dp);
        }
        else{
            //sideway jump
            int ans = INT_MAX;
            for(int i = 1; i<= 3; i++){
                if(obstacles[curPos] != i and currlane != i){
                    ans = min(ans, 1+ solveMem(obstacles, i, curPos,dp));
                    dp[currlane][curPos] = ans;
                }
            }
            return dp[currlane][curPos];  
        }
    }
    
    int solveTab(vector<int>& obstacles){
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4,vector<int>(n+1,1e9));
        //Base Case
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0; 
        
        for(int pos = n-1; pos >=0; pos--){
            for(int lane = 1; lane<= 3; lane++){
                if(obstacles[pos + 1] != lane){
                    dp[lane][pos] = dp[lane][pos + 1];
                 }
        else{
            //sideway jump
            int ans = 1e9;
            for(int i = 1; i<= 3; i++){
                if(obstacles[pos] != i and lane != i){
                    ans = min(ans, 1+ dp[i][pos+1]);
                    
                }
            }
            dp[lane][pos] = ans;  
        }
                
            }
        }
        return min(dp[2][0],min(1+ dp[1][0], 1+dp[3][0]));
    }
    
    int minSideJumps(vector<int>& obstacles) {
        //  int n = obstacles.size() - 1;
        // vector<vector<int>> dp(4,vector<int>(n+1,-1));
        // return solveMem(obstacles, 2, 0,dp);
        
        return solveTab(obstacles);
    }
};