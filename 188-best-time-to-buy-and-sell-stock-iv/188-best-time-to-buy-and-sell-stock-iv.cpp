class Solution {
public:
    int solveMem(int index, int opNo, int k,vector<int>& prices,vector<vector<int>>&dp){
        if(index == prices.size())
            return 0;
        
        if( opNo == 2*k)
            return 0;
        if(dp[index][opNo] != -1)
            return dp[index][opNo];
        
        int profit = 0;
        if(opNo %2 == 0){
            int isBuy = -prices[index] + solveMem( index+1, opNo+1,k,prices,dp);
            int notBuy =  0 +  solveMem( index+1, opNo,k,prices,dp);   
            profit = max(isBuy, notBuy);
        }
        else{
            int isSell = prices[index] + solveMem( index+1, opNo+1,k,prices,dp);
            int notSell =  0 +  solveMem( index+1,opNo,k,prices,dp);   
            profit = max(isSell, notSell);
        }
        return dp[index][opNo] = profit;
    }
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
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int>(2*k, -1));
        return solveMem(0,0,k,prices,dp);
        //return solveTab(k,prices);
    }
};