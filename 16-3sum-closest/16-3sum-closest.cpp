class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int diff= INT_MAX;
        for(int i = 0; i<n ; i++){
            //first element
            int first = nums[i];
            int left = i+1;
            int right = n-1;
            
            while( left < right){
                if(first + nums[left] + nums[right] == target)
                    return target;
                else if(abs(first + nums[left] + nums[right] - target) < diff)
                {
                    diff = abs(first + nums[left] + nums[right] - target);
                    ans = first + nums[left] + nums[right];
                }
                if(first + nums[left] + nums[right] > target)
                    right--;
                else
                    left++;
            }
            
            
        }
        return ans ;
    }
};