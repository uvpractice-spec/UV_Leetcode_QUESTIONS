class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        

        int n= digits.size();

        for(int i = n-1;i>=0;i--){

            if(digits[i] < 9){
                digits[i]++;  // digit is not less than 9 so just plusone  7->8
                return digits;
            }

            digits[i]=0; // digits is 9 so add 0 in that place
        }

        digits.insert(digits.begin(),1); // all dgits are 9 so  0 will add but add 1 at start of it

        return digits;
    }
};