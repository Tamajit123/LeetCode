class Solution {
public:
    
    int solve(int index, int buy,vector<int>& prices ,vector<vector<int>>&dp){
    
    if(index == prices.size())
        return 0;
    
    int maxProfit = 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        if(buy){
            maxProfit += max((-prices[index] + solve(index+1,0,prices,dp)), (0 +solve(index+1,1,prices,dp))  );
        }
        
        else{
            maxProfit += max( (prices[index] + solve(index+1, 1, prices,dp)) , (0+ solve(index+1, 0, prices,dp)) );
        }
        return dp[index][buy] = maxProfit;
    }

    
    int solveTab(vector<int>& prices){
        
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
            maxProfit = max( (prices[index] + dp[index+1][1]) , (0+ dp[index+1][0]) );
        }
                dp[index][buy] = maxProfit;
                
            }
        }
        
        return dp[0][1];
    }
    

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int> >dp(n, vector<int>(2,-1));
        // return solve(0, 1, prices,dp);
        return solveTab(prices);
    }
};