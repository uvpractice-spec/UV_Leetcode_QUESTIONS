class Solution {
public:
    long long kadane(const vector<int>& arr, int repeat) {
        long long maxEndingHere = 0;
        long long maxSoFar = 0;
        int n = arr.size();

        for (int i = 0; i < n * repeat; ++i) {
            maxEndingHere = max(0LL, maxEndingHere + arr[i % n]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int MOD = 1e9 + 7;

        
        if (k == 1) {
            return kadane(arr, 1) % MOD;
        }

      
        long long totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        long long maxTwoCopies = kadane(arr, 2);

       
        if (totalSum > 0) {
             long long total = (maxTwoCopies + (k - 2) * totalSum) % MOD;
            return total;
        } else {
          
            return maxTwoCopies % MOD;
        }
    }
};