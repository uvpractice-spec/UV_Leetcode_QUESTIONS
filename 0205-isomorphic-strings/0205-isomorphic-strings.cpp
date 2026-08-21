class Solution {
public:
    bool isIsomorphic(string s, string t) {
        

        int posS[256] = {0};
        int posT[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            // Check if last seen positions match
            if (posS[s[i]] != posT[t[i]]) {
                return false;
            }

            // Store index + 1 (1-based to distinguish from default 0)
            posS[s[i]] = i + 1;
            posT[t[i]] = i + 1;
        }

        return true;
    }
};