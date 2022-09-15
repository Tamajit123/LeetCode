class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int s = 0; 
        int e = nums.size() - 1;
        
        while(s <=e){
            if(nums[s] <= nums[e]){
             ans = min(ans,nums[s]);
                break;
            }
            int mid = s + (e-s)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[s])
                s = mid+1;
            else
                e = mid-1;
        }
        return ans;
    }
};