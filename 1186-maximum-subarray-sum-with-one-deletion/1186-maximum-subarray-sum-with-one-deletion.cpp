class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = arr.size();
        
       
        int noDelete = arr[0];
        int oneDelete = 0; 
        int maxOverall = arr[0];

        for (int i = 1; i < n; ++i) {
            int x = arr[i];
            
            
            oneDelete = max(noDelete, oneDelete + x);
            noDelete = max(x, noDelete + x);

            maxOverall = max({maxOverall, noDelete, oneDelete});
        }

        return maxOverall;
    }
};