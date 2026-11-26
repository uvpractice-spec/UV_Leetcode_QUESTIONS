class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.size();
       
        if (n < 4 || n > 12) return result;

        vector<string> segments;
        backtrack(0, s, segments, result);
        return result;
    }

    private:
    void backtrack(int start, const string& s, vector<string>& segments, vector<string>& result) {
       
        if (segments.size() == 4) {
            if (start == s.size()) {
                result.push_back(segments[0] + "." + segments[1] + "." + segments[2] + "." + segments[3]);
            }
            return;
        }

      
        int remainingChars = s.size() - start;
        int remainingSegments = 4 - segments.size();
        if (remainingChars < remainingSegments || remainingChars > remainingSegments * 3) {
            return;
        }

        int num = 0;
        for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
           
            if (len > 1 && s[start] == '0') break;

            num = num * 10 + (s[start + len - 1] - '0');
            if (num > 255) break;

            segments.push_back(s.substr(start, len));
            backtrack(start + len, s, segments, result);
            segments.pop_back();
        }
    }
};