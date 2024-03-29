class Solution {
public:
    bool check(vector<int>base, vector<int> newBox){
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
            return true;
        else
            return false;
    }
    int solveSO(int n, vector<vector<int>>& a){
        
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1,0);
        
        for(int curr = n-1; curr >=0; curr--){
            for(int prev = curr-1; prev >= -1 ; prev--){
                int incld = 0;
        
        if(prev == -1 || check(a[curr] ,a[prev])){
            incld = a[curr][2] + nextRow[curr+1];
        }
        
        int exclude = 0 + nextRow[prev+1];
        
        currRow[prev+1] = max(incld, exclude);
                
            }
            nextRow = currRow;
        }
      return nextRow[0];  
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a :cuboids ){
            sort(a.begin(), a.end());
        }
        
        sort(cuboids.begin(), cuboids.end());
        
        return solveSO(cuboids.size(), cuboids);
    }
};