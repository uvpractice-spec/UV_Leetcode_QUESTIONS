/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer;
        stack<pair<int, int>> st; // Stores {value, index}
        
        ListNode* curr = head;
        int index = 0;
        
        while (curr != nullptr) {
           
            answer.push_back(0);
            
            
            while (!st.empty() && st.top().first < curr->val) {
                answer[st.top().second] = curr->val;
                st.pop();
            }
            
        
            st.push({curr->val, index});
            
            curr = curr->next;
            index++;
        }
        
        return answer;
    }
};