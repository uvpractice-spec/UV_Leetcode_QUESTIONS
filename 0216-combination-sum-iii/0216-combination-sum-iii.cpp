class Solution {
public:
     
     void backtrack(int k, int target, int start, vector<int>& path, vector<vector<int>>& result) {
     
        if (target == 0 && path.size() == k) {
            result.push_back(path);
            return;
        }

       
        if (path.size() >= k || target <= 0) {
            return;
        }

        for (int i = start; i <= 9; ++i) {
            
            if (i > target) break;

            path.push_back(i);
            backtrack(k, target - i, i + 1, path, result);
            path.pop_back(); 
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<std::vector<int>> result;
        vector<int> path;

       
        int minSum = k * (k + 1) / 2;
        int maxSum = k * (19 - k) / 2;

        if (n < minSum || n > maxSum) {
            return result;
        }

        backtrack(k, n, 1, path, result);
        return result;

    }
};