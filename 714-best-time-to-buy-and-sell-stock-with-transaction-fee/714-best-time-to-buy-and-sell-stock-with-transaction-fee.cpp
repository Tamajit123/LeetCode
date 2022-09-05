class Solution {
public:
    
    int solveTab(vector<int>& prices, int fee){
        
        int n = prices.size();
        
        vector<vector<int> >dp(n+1, vector<int>(2,0));

    int maxProfit = 0;
      
        for(int index = n-1; index>=0; index--){
            for(int buy = 0;buy <=1; buy++){
                
        if(buy){
            int isBuy = -prices[index] + dp[index+1][0];
            int notBuy = 0 +dp[index+1][1];
            maxProfit = max(isBuy, notBuy );
        }
        
        else{
            maxProfit = max( (prices[index] - fee + dp[index+1][1]) , (0+ dp[index+1][0]) );
        }
                dp[index][buy] = maxProfit;
                
            }
        }
        
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int> >dp(n+1, vector<int>(2,0));
        // return solve(0, 1,prices,fee,dp);
        return solveTab(prices, fee);
    }
};