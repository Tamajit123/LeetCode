class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
    int maxProfit = 0;
    int minsoFar= prices[0];
        
        for(int i=0; i<prices.size(); i++){
            minsoFar = min(minsoFar,prices[i]);
            int profit = prices[i] - minsoFar;
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
        
    }
};