class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m = haystack.length();
        int n = needle.length();

        if (n == 0) return 0;

        vector<int> lps(n, 0);
        int len = 0; 
        int i = 1;

        while (i < n) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; 
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        
        int h = 0;
        int nd = 0; 

        while (h < m) {
            if (haystack[h] == needle[nd]) {
                h++;
                nd++;
            }

            if (nd == n) {
                return h - nd; 
            } 
            else if (h < m && haystack[h] != needle[nd]) {
                if (nd != 0) {
                    nd = lps[nd - 1]; 
                } else {
                    h++;
                }
            }
        }

        return -1;
    }
};