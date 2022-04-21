class Solution {
public:
    
    void comB(string digits, vector<string>& ans, string output, int index,  string mapping[]){
        
        //Base Case
        if( index >= digits.length()){
            ans.push_back(output);
            return;
        }
        
        int number = digits[index] - '0';
        string value = mapping[number] ;
        for(int i = 0; i<value.length(); i++){
            output.push_back(value[i]);
             comB(digits, ans, output, index+1, mapping);
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        int index = 0 ;
        string output = "" ;
        
        if(digits.length() == 0){
            return ans;
        }
        
        string mapping[10] = {"", "" , "abc","def","ghi","jkl","mno","pqrs" ,"tuv","wxyz"} ;
        comB(digits, ans, output, index, mapping);
        return ans;
    }
};