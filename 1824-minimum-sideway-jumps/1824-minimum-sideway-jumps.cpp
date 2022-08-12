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
        
    int minSideJumps(vector<int>& obstacles) {
         int n = obstacles.size() - 1;
        vector<vector<int>> dp(4,vector<int>(n+1,-1));
        return solveMem(obstacles, 2, 0,dp);
    }
};