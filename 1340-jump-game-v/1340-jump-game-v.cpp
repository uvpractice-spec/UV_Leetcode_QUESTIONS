class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = arr.size();
        vector<vector<int>> adj(n);
        vector<int> st;

  
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.back()] <= arr[i]) {
                st.pop_back();
            }
            if (!st.empty() && i - st.back() <= d) {
                adj[st.back()].push_back(i); 
            }
            st.push_back(i);
        }

   
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.back()] <= arr[i]) {
                st.pop_back();
            }
            if (!st.empty() && st.back() - i <= d) {
                adj[st.back()].push_back(i); 
            }
            st.push_back(i);
        }

    
        vector<int> memo(n, -1);
        auto dfs = [&](auto& self, int u) -> int {
            if (memo[u] != -1) return memo[u];
            
            int max_len = 1;
            for (int v : adj[u]) {
                max_len = max(max_len, 1 + self(self, v));
            }
            return memo[u] = max_len;
        };

        int max_jumps = 0;
        for (int i = 0; i < n; ++i) {
            max_jumps = max(max_jumps, dfs(dfs, i));
        }

        return max_jumps;
    }
};