class Solution {
public:
    int compress(vector<char>& chars) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int write = 0; 
        int i = 0;     

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

          
            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }

          
            chars[write++] = currentChar;

           
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        return write; 
    }
};