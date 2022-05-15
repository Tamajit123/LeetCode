class Solution {
public:
    void sortColors(vector<int>& nums) {
     int size = nums.size();
        int i = 0, j = 0, k = size - 1; 
        
        while(i <= k){
            if(nums[i] == 0)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            
            else if(nums[i] == 1){
                i++;
            }
            else{
                swap(nums[i], nums[k]);
                k--;
            }
        }
    }
};