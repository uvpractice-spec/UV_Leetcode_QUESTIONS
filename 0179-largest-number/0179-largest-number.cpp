class Solution {
public:
    string largestNumber(vector<int>& nums) {
        

        vector<string> strnum;

        for(int x : nums){
            strnum.push_back(to_string(x));
        }

        sort(strnum.begin(),strnum.end(),[](const string &a,const string &b){
            return a+b > b+a;
        });
        
        if (strnum[0] == "0") {
            return "0";
        }

        string result ="";
        for(string s : strnum){
            result+=s;
        }


        return result;

    }
};