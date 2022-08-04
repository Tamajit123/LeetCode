class Solution {
public:
    int solveMem(int i, int j, vector<vector<char>> &matrix,vector<vector<int>> &dp,int &maxi){
        
        //Base Case
        //int ans ;
         if(matrix.size() <=i || matrix[0].size() <=j)
         return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        
        int right = solveMem(i, j+1, matrix,dp,maxi);
        int diagonal = solveMem(i +1, j+1, matrix,dp,maxi);
        int down = solveMem(i+1, j, matrix,dp,maxi);
        
        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(diagonal,down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            
            return dp[i][j] = 0;
        }
       
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size() +1,-1));
        solveMem(0, 0, matrix,dp,maxi);
        return maxi*maxi; 
    }
};