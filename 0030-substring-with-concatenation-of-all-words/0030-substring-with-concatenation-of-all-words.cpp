class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        if (s.length() < totalLen) return result;
        
        unordered_map<string, int> wordMap;
        for (const string& w : words) {
            wordMap[w]++;
        }
        
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seenMap;
            int count = 0;
            
            while (right + wordLen <= s.length()) {
                string sub = s.substr(right, wordLen);
                right += wordLen;
                
                if (wordMap.find(sub) != wordMap.end()) {
                    seenMap[sub]++;
                    count++;
                    
                    while (seenMap[sub] > wordMap[sub]) {
                        string leftSub = s.substr(left, wordLen);
                        seenMap[leftSub]--;
                        left += wordLen;
                        count--;
                    }
                    
                  
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                  
                    seenMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};