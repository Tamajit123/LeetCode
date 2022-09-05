class Solution {
public:
    int solve(int curr1,int curr2,string &text1, string &text2,vector<vector<int>>&dp ){
        if(curr1 == text1.length() or curr2 == text2.length())
            return 0;
        
        if(dp[curr1][curr2] != -1)
            return dp[curr1][curr2];
        int ans = 0;
        
        if( text1[curr1] == text2[curr2])
           {
                ans = 1 + solve(curr1+1, curr2+1, text1, text2,dp);
           }
        else
             ans = max(solve(curr1+1,curr2, text1,text2,dp), (solve(curr1,curr2+1, text1,text2,dp)));
        
        return dp[curr1][curr2] = ans;
        
    }
    
    int solveTab(string &text1, string &text2 ){
        int l1 = text1.length();
        int l2 = text2.length();
        
        vector<vector<int>>dp(l1+1, vector<int>(l2+1,0));
       
        int ans = 0;
        
        for(int curr1 = l1 -1; curr1>=0; curr1--){
            for(int curr2 = l2 -1; curr2 >=0 ; curr2--){
                if( text1[curr1] == text2[curr2])
           {
                ans = 1 + dp[curr1+1][curr2+1];
           }
        else
             ans = max(dp[curr1+1][curr2], dp[curr1][curr2+1]);
        
              dp[curr1][curr2] = ans;
            }
        }
        
        return dp[0][0];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
//         int l1 = text1.length();
//         int l2 = text2.length();
//         vector<vector<int>> dp(l1, vector<int>(l2,-1));
        
//         return solve(0, 0, text1,text2,dp);
        
        return solveTab(text1, text2);
    }
};