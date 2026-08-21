class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";

        
        for (char c : s) {
           
            if (c >= 'a' && c <= 'z') {
                clean += c;
            }
           
            else if (c >= 'A' && c <= 'Z') {
                clean += (c + 32); 
            }
            
            else if (c >= '0' && c <= '9') {
                clean += c;
            }
           
        }

       
        int left = 0;
        int right = clean.length() - 1;

        while (left < right) {
            if (clean[left] != clean[right]) {
                return false; 
            }
            left++;
            right--;
        }

        return true; 
    }
};