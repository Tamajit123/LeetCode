class Solution {
public:
    int solve(string &a, string &b,int i, int j,vector<vector<int>> &dp) {
        if(i == a.length())
            return b.length() - j;
        
        if(j == b.length())
            return a.length() - i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        
        if(a[i] == b[j]){
            return solve(a, b , i+1, j+1,dp);
        }
        
        else{
               int inAns = 1 + solve(a,b, i, j+1,dp);
               int delAns = 1+ solve(a,b,i+1, j,dp);
               int repAns = 1+ solve(a,b, i+1, j+1,dp); 
               ans = min(inAns,min(delAns,repAns) );
            }
        
        return dp[i][j] = ans;
    }
    
    int solveTab(string &word1, string &word2){
        int l1= word1.length();
        int l2 = word2.length();
        
        vector<vector<int>> dp(l1+1, vector<int>(l2+1,0));
        int ans = 0 ;
        
        for(int j = 0; j<l2; j++){
            dp[l1][j] = l2 - j;
        }
        for(int i = 0; i<l1; i++){
          dp[i][l2] = l1 - i;  
        }
        
        for(int i = l1 -1; i>=0; i--){
            for(int j = l2-1; j>= 0 ; j--){
                if(word1[i] == word2[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int inAns = 1+ dp[i][j+1];
                    int delAns = 1+ dp[i+1][j];
                    int repAns = 1+ dp[i+1][j+1];
                    ans = min(inAns, min(delAns, repAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    
    int solveSpace(string &word1, string &word2){
        int l1= word1.length();
        int l2 = word2.length();
        
        //vector<vector<int>> dp(l1+1, vector<int>(l2+1,0));
        vector<int>curr(l2+1,0);
        vector<int>next(l2+1,0);
        
        int ans = 0 ;
        
        for(int j = 0; j<l2; j++){
            next[j] = l2 - j;
        }

        for(int i = l1 -1; i>=0; i--){
            for(int j = l2-1; j>= 0 ; j--){
                //Important 
                curr[l2] = l1 - i;
                
                if(word1[i] == word2[j]){
                    ans = next[j+1];
                }
                else{
                    int inAns = 1+ curr[j+1];
                    int delAns = 1+ next[j];
                    int repAns = 1+ next[j+1];
                    ans = min(inAns, min(delAns, repAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    
    
    int minDistance(string word1, string word2) {
        
        int l1= word1.length();
        int l2 = word2.length();
        
//         vector<vector<int>> dp(l1+1, vector<int>(l2+1,-1));
//         return solve(word1,word2, 0, 0,dp);
        //return solveTab(word1, word2);
        
        if(l1 == 0)
            return l2;
        if(l2 == 0)
            return l1;
        
        return solveSpace(word1, word2);
    }
};