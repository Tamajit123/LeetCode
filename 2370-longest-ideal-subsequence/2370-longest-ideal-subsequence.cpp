class Solution {
public:
    int solveMem(string &s,int k,int curr,int prev,vector<vector<int>>& dp){
        //Base Case
        if(curr < 0){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1)
        return dp[curr][prev+1];
        
        int incld = 0;
        
        if(prev == -1 || abs((s[curr] - 'a') - (s[prev] - 'a'))<=k){
            incld = 1 + solveMem(s,k , curr - 1, curr, dp);
        }
        
        int exclude = 0 + solveMem(s, k , curr - 1 , prev,dp);
        int ans  = max(incld, exclude);
        return dp[curr][prev+1] = ans;
        
    }
    int solveTab(string &s,int k){
        
        int n = s.size();
        //vector<vector<int> >dp(n+1, vector<int>(n+1, 0));
        vector<int> curr(27,0), next(27,0);
        
        for(int index = n-1; index>=0; index--){
            for(int prev = 26; prev >=0 ; prev--){
                int incld = 0;
                if(prev == 26 || abs(s[index] - 'a' - prev ) <=k){
                    incld = 1 + next[s[index] - 'a'];
                }
                int excld = 0 + next[prev];
                curr[prev] = max(incld, excld);
            }
            next = curr;
        }
        
        return curr[26];
    }
    
    int longestIdealString(string s, int k) {
        // int n = s.size();
        // vector<vector<int> >dp(n+1, vector<int>(n+1, -1));
        // return solveMem(s , k, n-1 , -1, dp );
        return solveTab(s,k);
    }
};