class Solution {
public:
//     int solve(string &s, string &t, int i, int j ,vector<vector<int>>&dp){
//         if( i == 0 or j == 0)
//             return 0 ;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(s[i-1] == t[j-1])
//             return dp[i][j] = 1 + solve(s , t , i-1, j-1, dp);
        
//         else
//             return dp[i][j] = solve(s, t, i, j-1,dp);
//     }
//     bool isSubsequence(string s, string t) {
//         int m = s.length();
//         int n = t.length();
        
// //         if( m> n)
// //             return false;
        
//         vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        
        
//         // if(solve(s, t, m , n , dp ))
//         //     return true;
//         // else
//         //     return false;
//         return solve(s, t, m , n , dp);
//     }
    bool isSubsequence(string s, string t){
        int sl = s.size();
        int tl = t.size();
        
        int i = 0;
        
        for(int j = 0; j< tl; j++){
            if(s[i] == t[j]){
                i++;
            }
            if( i == sl)break;
        }
        return i == sl;
    }
};