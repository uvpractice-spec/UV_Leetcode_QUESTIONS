class Solution {
public:
    string clearStars(string s) {
        
        int n = s.length();
        
        vector<int> pos[26];
        
        vector<bool> removed(n, false);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                removed[i] = true; 

               
                for (int c = 0; c < 26; ++c) {
                    if (!pos[c].empty()) {
                        
                        int rightmost_idx = pos[c].back();
                        pos[c].pop_back();
                        removed[rightmost_idx] = true;
                        break; 
                    }
                }
            } else {
               
                pos[s[i] - 'a'].push_back(i);
            }
        }

        
        string result = "";
        for (int i = 0; i < n; ++i) {
            if (!removed[i]) {
                result += s[i];
            }
        }

        return result;
    }
};