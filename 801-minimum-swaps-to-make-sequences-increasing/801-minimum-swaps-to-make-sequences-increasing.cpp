class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool isSwap,vector<vector<int>> &dp){
        
        if(index == nums1.size())
            return 0;
        
        if(dp[index][isSwap] != -1)
            return dp[index][isSwap];
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        if(isSwap)
            swap(prev1, prev2);
        
        int ans  = INT_MAX;
        //No swap
        if(nums1[index] > prev1 and nums2[index] > prev2)
            ans = solve(nums1,nums2, index+1, 0,dp);
        
        //swap
        if(nums1[index] > prev2 and nums2[index] > prev1)
            ans = min(ans, 1+solve(nums1,nums2, index+1, 1,dp));
        
        return dp[index][isSwap] = ans;
    }
    
    
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(2, 0));
        
        // if(index == nums1.size())
        //     return 0;

        
        
        for(int index = n-1; index >=1; index--){
            for(int isSwap = 1; isSwap >= 0; isSwap --){
                
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];
        
                if(isSwap)
                    swap(prev1, prev2);
        
                int ans  = INT_MAX;
                
                if(nums1[index] > prev1 and nums2[index] > prev2)
                    ans = dp[index+1][0];
                if(nums1[index] > prev2 and nums2[index] > prev1)
                    ans = min(ans, 1+dp[index+1][1]);
                
                dp[index][isSwap] = ans;
            }
        }
        
        return dp[1][0];
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        bool isSwap = 0;
        int n= nums1.size();
        // vector<vector<int>>dp(n ,vector<int>(2, -1));
        // return solve(nums1, nums2, 1,isSwap,dp);
        
        return solveTab(nums1,nums2);
    }
};