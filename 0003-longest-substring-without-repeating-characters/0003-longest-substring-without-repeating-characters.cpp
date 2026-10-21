class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> charMap;
        int left = 0, maxLength = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            
            
            if (charMap.find(c) != charMap.end() && charMap[c] >= left) {
                left = charMap[c] + 1;
            }
            
            charMap[c] = right;
            
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};