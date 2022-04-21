class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
    int maxProfit = 0;
    int minsoFar= prices[0];
        
        for(int i=0; i<prices.size(); i++){
            minsoFar = std::min(minsoFar,prices[i]);
            int profit = prices[i] - minsoFar;
            maxProfit = std::max(maxProfit,profit);
        }
        return maxProfit;
    }
};