class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length()-1;
        int count=0;
        bool flag=false;
        for(int i=n;i>=0;i--){
            if( s[i] == ' '  &&  flag == true){
                break;
            }
            else if(s[i] != ' '){
                flag=true;
                count++;
            }
        }
        return count;
    }
};