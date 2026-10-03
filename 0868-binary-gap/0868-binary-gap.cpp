class Solution {
public:
    int binaryGap(int n) {
        

        int max_gap = 0;
        int last_pos = -1;

        while (n > 0) {
          
            int pos = __builtin_ctz(n);

            if (last_pos != -1) {
                max_gap = std::max(max_gap, pos - last_pos);
            }
            last_pos = pos;

          
            n &= (n - 1);
        }

        return max_gap;
    }
};