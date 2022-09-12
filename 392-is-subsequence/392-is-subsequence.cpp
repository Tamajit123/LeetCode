class Solution {
public:
    bool isSubsequence(string s, string t){
        int sl = s.size();
        int tl = t.size();
        
        int i = 0;
        
        for(int j = 0; j< tl; j++){
            if(s[i] == t[j]){
                i++;
            }
            if( i == sl)break;
        }
        return i == sl;
    }
};