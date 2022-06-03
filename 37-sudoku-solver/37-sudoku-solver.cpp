class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int val){
    //row and col check
    for(int i = 0; i< board.size(); i++){
    if(board[row][i] == val or board[i][col] == val)
        return false;
    //3x3 matrix check
    if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
        return false;
    }
   }
    return true;
}

bool solution(vector<vector<char>>& board){
    int n = board.size();
    
    for(char i = 0; i<n; i++){
       for(char j =0; j<n ; j++){
           if(board[i][j] == '.'){
               for(char val = '1'; val <='9'; val++){
                   if( isSafe(i,j,board,val)){
                       board[i][j] = val;
                       //recurrsive call
                       bool nextSol = solution(board);
                       if(nextSol)
                           return true;
                       else{
                           //backtrack
                           board[i][j] = '.';
                       }
                   }
               }
               return false;
           }
       } 
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solution(board);
    }
};