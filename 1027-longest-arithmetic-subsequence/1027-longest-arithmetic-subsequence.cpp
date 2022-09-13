class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <=2)
            return n;
        
        unordered_map<int,int> dp[n+1];
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                int diff = nums[i] - nums[j];
                
                int cnt = 1;
                
                //Check
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                dp[i][diff] = 1 + cnt;
                ans  = max(ans,dp[i][diff]);
            }
        }
        return ans; 
    }
};