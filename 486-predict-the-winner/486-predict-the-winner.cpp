class Solution {
public:
    int solve(vector<int>& nums, int i , int j,vector<vector<int>> &dp){
        if(i > j)
            return 0;
        
        if( i == j)
            return nums[i];
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int op1 = nums[i] + min(solve(nums, i+2,j,dp), solve(nums,i+1, j-1,dp));
        int op2 = nums[j] + min( solve(nums, i, j-2,dp) , solve(nums, i+1, j-1,dp));
        
        return dp[i][j] = max(op1,op2);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        
        int p1_score = solve(nums,0,nums.size() - 1,dp);
        int total_score  = 0;
        
        for(int i = 0; i< nums.size(); i++){
            total_score += nums[i];
        }
        int p2_score = total_score - p1_score;
        
        if(p1_score >= p2_score)
            return true;
        else
            return false;
                
    }
};