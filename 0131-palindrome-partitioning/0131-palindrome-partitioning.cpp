class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int end = 0; end < n; ++end) {
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start <= 2 || isPal[start + 1][end - 1])) {
                    isPal[start][end] = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, isPal, path, result);
        return result;
    }

    private:
    void backtrack(int start, const string& s, const vector<vector<bool>>& isPal,
                   vector<string>& path, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPal[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, isPal, path, result);
                path.pop_back();
            }
        }
    }
};