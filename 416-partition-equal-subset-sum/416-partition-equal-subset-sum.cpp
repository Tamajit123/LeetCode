class Solution {
public:
    bool solveSO(vector<int>& nums, int n , int sum){
        n = nums.size();
        
        vector<int> curr(sum+1, 0);
        vector<int> next(sum+1, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int index = n-1; index >=0; index--){
            for(int target = 0; target <= sum/2; target++){
                bool incld = 0;
                if(target - nums[index] >= 0){
                    incld = next[target - nums[index]];
                }
                bool excld = next[target];
                curr[target] = incld or excld;
            }
            next = curr;
        }
        return next[sum/2];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            sum += nums[i];
        }
        
        if( sum & 1)
            return 0;
        
        int target = sum/2;
        
        return solveSO(nums,n,sum);
    }
};