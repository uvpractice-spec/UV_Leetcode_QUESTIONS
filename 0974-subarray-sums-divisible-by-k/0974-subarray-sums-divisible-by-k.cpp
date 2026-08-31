class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> modc(k,0);

        modc[0]=1;
        int curr=0;
        int total =0;

        for(int x :nums){

            curr+=x;

            int rem = (curr % k + k ) % k;

            total += modc[rem];

            modc[rem]++;
        }

        return total;
    }
};