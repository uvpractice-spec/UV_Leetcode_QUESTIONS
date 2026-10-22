class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        
      
        int n = s.length();
        vector<vector<char>> buckets(n + 1);
        for (auto& [ch, freq] : freqMap) {
            buckets[freq].push_back(ch);
        }
        
       
        string result = "";
        for (int i = n; i > 0; --i) {
            for (char ch : buckets[i]) {
                result.append(i, ch); 
            }
        }
        
        return result;
    }
};