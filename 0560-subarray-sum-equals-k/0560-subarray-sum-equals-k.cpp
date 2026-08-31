class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int,int> prefix;

        int currsum=0;
        int totalsum=0;

        prefix[0]=1;

        for(int x : nums){

            currsum+=x;

            if(prefix.contains(currsum - k)){
                totalsum+=prefix[currsum-k];
            }

            prefix[currsum]++;
        }

        return totalsum;
    }
};