class Solution {
public:

    void helper(int open ,int close , string curr, vector<string> &result,int n ){

        if(open ==n && close ==n){
            result.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            helper(open +1,close,curr,result,n);
            curr.pop_back();
        }

        if(close < open ){
            curr.push_back(')');
            helper(open,close+1,curr,result,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        string curr;

        curr.reserve(2 *n);

        helper(0,0,curr,result,n);

        return result;

    }
};