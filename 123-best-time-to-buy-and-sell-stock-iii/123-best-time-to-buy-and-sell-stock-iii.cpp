class Solution {
public:
    int solve(int index,int buy,int limit,vector<int>& prices,vector<vector<vector<int>>> &dp){
        int n = prices.size();
        
        if(index == n)
            return 0;
        
        if(limit == 0)
            return 0;
        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        
        int profit = 0;
        
        if(buy){
            int isBuy = -prices[index] + solve( index+1, 0, limit,prices,dp);
            int notBuy =  0 +  solve( index+1, 1, limit,prices,dp);   
            profit = max(isBuy, notBuy);
        }
        else{
            int isSell = prices[index] + solve( index+1, 1, limit-1,prices,dp);
            int notSell =  0 +  solve( index+1, 0, limit,prices,dp);   
            profit = max(isSell, notSell);
        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3, -1)));
        return solve(0,1,2,prices,dp);
    }
};