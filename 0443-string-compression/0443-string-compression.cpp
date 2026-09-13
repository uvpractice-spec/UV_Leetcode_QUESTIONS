class Solution {
public:
    int compress(vector<char>& chars) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int write = 0; 
        int read = 0;  
        int n = chars.size();

        while (read < n) {
            char currChar = chars[read];
            int start = read;

            while (read < n && chars[read] == currChar) {
                read++;
            }

            int count = read - start;

            
            chars[write++] = currChar;

            if (count > 1) {
                int digitsStart = write;

                while (count > 0) {
                    chars[write++] = (count % 10) + '0';
                    count /= 10;
                }

                
                reverse(chars.begin() + digitsStart, chars.begin() + write);
            }
        }

        return write;
    }
};