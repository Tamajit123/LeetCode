class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n,vector<int>(n));
        int top= 0 ;
        int left = 0 ;
        int count=1;
      //  int total =n*n;
        int bottom= n-1 ;
        int right = n-1 ;
        vector<vector<int>> matrix;
        
        while(top<=bottom && left<=right){
            for(int i=left; i<= right; i++){
                ans[top][i]= count++;
        }
            top++;
            
         for(int i=top; i<= bottom; i++){
             ans[i][right]= count++;
         }
            right--;
            if(top<=bottom){
                 for(int i = right; i>= left; i--){
                ans[bottom][i]= count++;
            }
            bottom--;
            }
           if(left<=right){
                for(int i = bottom; i>= top; i--){
                ans[i][left]= count++;
            }
            left++;

           }
        }
        return ans;
    }
     
};