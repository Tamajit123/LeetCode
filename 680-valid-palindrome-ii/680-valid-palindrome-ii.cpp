class Solution {
public:
    bool validPalindrome(string s) {

    int start=0;
        int end=s.length()-1;
        int count1=0,count2=0;
                
        while(start<end){
            if(s.at(start)==s.at(end)){
                start++;
                end--;
            }
                else{
                    start++;
                    count1++;
                    
                }
            }
        start=0;
        end=s.length()-1;
           while(start<end){
            if(s.at(start)==s.at(end)){
                start++;
                end--;
            }
                else{
                    end--;
                    count2++;
                    
                }
            }
        
         
    if(count1==1 or count2==1) 
        return true;
    if(count1==0 or count2==0) 
        return true;
    return false;
    
    }
};