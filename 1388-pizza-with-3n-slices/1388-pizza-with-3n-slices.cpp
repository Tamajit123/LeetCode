class Solution {
public:
    int solveMem(int index, int endInd, vector<int>& slices, int n,vector<vector<int>> &dp){
        if( n == 0 or index > endInd)
            return 0;
        
        if(dp[index][n] != -1)
            return dp[index][n];
        
        
        int incld = slices[index] + solveMem(index + 2, endInd, slices, n-1,dp);
        int excld = solveMem(index + 1, endInd, slices, n,dp);
        
        return dp[index][n] = max(incld, excld);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        
        vector<vector<int>> dp1(k, vector<int>(k,-1));
        int case1 = solveMem(0, k-2, slices, k/3,dp1);
        
        vector<vector<int>> dp2(k, vector<int>(k,-1));
        int case2 = solveMem(1, k-1, slices, k/3,dp2);
        
        return max(case1, case2);
                        
    }
};