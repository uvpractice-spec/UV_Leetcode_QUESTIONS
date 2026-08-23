class Solution {
public:
    int hammingDistance(int x, int y) {
        

        int xor_res = x ^ y;

        int distance = 0;

        while(xor_res > 0){
            xor_res &=(xor_res-1);
            distance++;
        }

        return distance;
    }
};