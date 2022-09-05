class Solution {
public:
    int solveTab(int k,vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(k+1, 0)));

        
        int profit = 0;
        
        for(int index = n-1; index >=0; index--){
            for(int buy = 0; buy <=1; buy++){
                for(int limit = 1; limit <=k; limit++){
                    if(buy){
            int isBuy = -prices[index] + dp[index+1][0][limit];
            int notBuy =  0 +  dp[index+1][1][limit];   
            profit = max(isBuy, notBuy);
        }
        else{
            int isSell = prices[index] + dp[index+1][1][limit-1];
            int notSell =  0 +  dp[index+1][0][limit];   
            profit = max(isSell, notSell);
        }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(k,prices);
    }
};