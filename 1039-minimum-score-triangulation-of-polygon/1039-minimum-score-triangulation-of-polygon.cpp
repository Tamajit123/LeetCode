class Solution {
public:
    int solveMem(vector<int>& values,int s,int e,vector<vector<int>> &dp){
        
        //Base Case
        if( s+1 == e)
            return 0;
        
        if(dp[s][e] != -1 )
            return dp[s][e];
        
        int ans = INT_MAX;
        for(int k = s+1; k<e; k++){
        ans = min(ans,(values[s]*values[e]*values[k]) + solveMem(values, s, k, dp) + solveMem(values, k,e,dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
        
    }
    
    int solveTab(vector<int>& values){
        int n = values.size();
        vector<vector<int> > dp(n,vector<int>(n,0));


        int ans = INT_MAX;
        for(int i=n-1; i>=0; i--){
            for(int j = i+2; j<n; j++){
                int ans = INT_MAX;
                for(int k = i+1; k<j; k++){
                ans = min(ans,(values[i]*values[j]*values[k]) + dp[i][k]+ dp[k][j] );
        }
        dp[i][j] = ans;
       
            }
        }
         return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solveMem(values,0,n-1,dp);
        
        return solveTab(values);
    }
};