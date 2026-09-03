class Solution {
public:
    string countAndSay(int n) {
        

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string s = "1";

        for (int i = 2; i <= n; ++i) {
            string nextSeq = "";
            int count = 1;

            for (int j = 0; j < s.length(); ++j) {
           
                if (j + 1 < s.length() && s[j] == s[j + 1]) {
                    count++;
                } else {
            
                    nextSeq += std::to_string(count) + s[j];
                    count = 1; 
                }
            }
            s = move(nextSeq); 
        }

        return s;
    }
};