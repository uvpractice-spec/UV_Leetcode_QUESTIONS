class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return max(maxpossible(nums1,nums2),maxpossible(nums2,nums1));
    }

    int maxpossible(vector<int> & A, vector<int>&B){


        int totalsumA=0;
        int curr=0;
        int maxso=0;

        for(int i=0;i<A.size();i++){

            totalsumA+=A[i];

            int diff = B[i]-A[i];

            curr= max(0,curr+diff);
            maxso = max(curr,maxso);
        }

        return maxso+totalsumA;


    }
};