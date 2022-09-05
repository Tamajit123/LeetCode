class Solution {
public:
    int solveTab(string &s, string &revStr ){
        int l1 = s.length();
        int l2 = revStr.length();
        
        vector<vector<int>>dp(l1+1, vector<int>(l2+1,0));
       
        int ans = 0;
        
        for(int curr1 = l1 -1; curr1>=0; curr1--){
            for(int curr2 = l2 -1; curr2 >=0 ; curr2--){
                if( s[curr1] == revStr[curr2])
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
    int longestPalindromeSubseq(string s) {
       string revStr = s;
       reverse(revStr.begin(), revStr.end());
        
        int ans = solveTab(s, revStr);
        return ans;
    }
     
};