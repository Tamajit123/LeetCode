class Solution {
public:
    void subSet(vector<int>& nums,vector<int> output, int index , vector<vector<int>>& ans){
        
        //base case
        if( index >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        
        //exclude
        subSet(nums, output ,index+1, ans);
        
        //include
        int ele = nums[index];
        output.push_back(ele);
        subSet(nums, output ,index+1, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
      vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
         subSet(nums, output ,index, ans);
        return ans;
    }
};