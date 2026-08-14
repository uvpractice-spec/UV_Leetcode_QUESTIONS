class Solution {
public:
    const std::vector<std::string> pad = {
        "",     "",     "abc",  "def", // 0,1,2,3
        "ghi",  "jkl",  "mno",         // 4,5,6
        "pqrs", "tuv",  "wxyz"         // 7,8,9
    };

    void helper(string &curr, vector<string>&result, int idx,string digits){

        if(idx == digits.length()){
            result.push_back(curr);
            return;
        }

       string letter = pad[digits[idx] - '0'];

        for(char c : letter){
            
            curr.push_back(c);
            helper(curr,result,idx+1,digits);
            curr.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
        
       string curr;
        vector<string> result;

        helper(curr,result,0,digits);
    
        return result;
    }
};