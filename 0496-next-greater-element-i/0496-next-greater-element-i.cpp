class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

       unordered_map<int, int> nge; 
       stack<int> st;

       
        for (int num : nums2) {
           
            while (!st.empty() && st.top() < num) {
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        
        vector<int> result;
        result.reserve(nums1.size());
        
        for (int num : nums1) {
            if (nge.count(num)) {
                result.push_back(nge[num]);
            } else {
                result.push_back(-1); 
            }
        }

        return result;
    }
};