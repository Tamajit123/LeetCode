class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>&a, const vector<int>& b){
            if(a[0] < b[0])
                return true;
            if(a[0] == b[0])
                return a[1] > b[1];
            
            return false;
        });
        
        
        int n = envelopes.size();
        
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        
        int len = 1;
        
        for(int i = 1; i< n; i++){
            auto index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]);
            if(index == ans.end()){
                len++;
                ans.push_back(envelopes[i][1]);
            }
            else
                *index = envelopes[i][1];
        }
        return len;
       
    }
};