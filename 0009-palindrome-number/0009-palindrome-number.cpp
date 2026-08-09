class Solution {
public:
    bool isPalindrome(int x) {
        int save = x;
        
        if(x < 0){
            return false;
        }
        int ans =0;
        while(x>0){
           int rem = x % 10;
        
        // Overflow Check if ans * 10 will exceed INT_MAX, return 0 
        if (ans > INT_MAX / 10) {
            return 0; 
        }
        
        ans = ans * 10 + rem;
        x = x / 10;
        }

        if(ans== save){
            return true;
        }else{
            return false;
        }
    }
};