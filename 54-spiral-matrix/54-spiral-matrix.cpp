class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        vector<int> ans;
        
        int count=0;
        int total= row * col;
        
        int stRow = 0;
        int enRow = row - 1;
        int stCol = 0;
        int enCol = col - 1;
        
        while(count<total){
            
            //starting row
            
            for(int i=stCol; count<total && i<=enCol; i++){
                ans.push_back(matrix[stRow][i]);
                count++;
            }
            stRow++;
            
            //ending col 
            
            for(int i=stRow; count<total && i<=enRow; i++){
                ans.push_back(matrix[i][enCol]);
                count++;
            }
            
            enCol--;
            
            //Ending Row
            
            for(int i=enCol; count<total && i>=stCol; i--){
                ans.push_back(matrix[enRow][i]);
                count++;
            }
            enRow--;
            
            //starting col
            
            for(int i=enRow; count<total && i>=stRow; i--){
                ans.push_back(matrix[i][stCol]);
                count++;
            }
            stCol++;
        }
        return ans;
    }
};