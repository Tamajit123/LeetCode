class Solution {
public:
    void perMut(vector<int>& nums, vector<vector<int>>& ans, int i){
        
        //Base case
        if(i >= nums.size() ){
            ans.push_back(nums);
            return;
        }
        
        for(int j = i; j< nums.size(); j++){
            swap(nums[i] , nums[j]);
            perMut(nums, ans, i+1);
            
            //backtracking
            swap(nums[i] , nums[j]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        perMut(nums, ans, i);
        return ans;
    }
};