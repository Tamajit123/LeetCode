
class Solution {
public:
   int solveTab(int d , int faces , int t){
      vector<vector<int>> dp(d+1,vector<int>(t+1, 0));
      
        dp[0][0] = 1;
        int mod = 1000000007;
       
        for(int dice = 1; dice<= d; dice++){
            for(int target = 1; target<= t; target++){
                int ans = 0;
                for(int i = 1; i<= faces; i++){
                    if( target - i >= 0){
                        ans += dp[dice-1][target-i];
                        ans = ans % mod;
                    }
                }
                dp[dice][target] = ans;
            }
        }
        
        return dp[d][t];
}
    int solveSO(int d , int faces , int t){
      vector<long long>curr(t+1,0);
        vector<long long>prev(t+1,0);
        
        
      
        prev[0] = 1;
        int mod = 1000000007;
       
        for(int dice = 1; dice<= d; dice++){
            for(int target = 1; target<= t; target++){
                int ans = 0;
                for(int i = 1; i<= faces; i++){
                    if( target - i >= 0){
                        ans = ans + prev[target-i];
                        ans = ans % mod;
                    }
                }
                curr[target] = ans;
            }
            prev = curr;
        }
        
        return prev[t];
}
    int numRollsToTarget(int n, int k, int target) {
        //vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        //return solveMem(n,k, target,dp);
        //return solveTab(n,k, target);
        return solveSO(n,k, target);
    }
};