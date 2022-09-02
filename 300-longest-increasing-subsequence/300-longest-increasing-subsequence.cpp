class Solution {
public:
    int solve(vector<int>& nums, int prev, int curr,vector<vector<int>>&dp){
        if(curr == nums.size())
            return 0;
        
        if(dp[prev+1][curr] != -1)
            return dp[prev+1][curr];
        
        int incld = 0;
        if(prev == -1 or nums[prev] < nums[curr]){
            incld = 1 + solve(nums, curr, curr+1, dp);   
        }
        int excld = 0 + solve(nums,prev, curr + 1, dp);
        
        return dp[prev+1][curr] = max(incld,excld);
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,-1,0,dp);
    }
};