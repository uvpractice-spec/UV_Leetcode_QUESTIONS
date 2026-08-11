class Solution {
public:
    int nextGreaterElement(int n) {
       // std::string s = std::to_string(n)
        std::string str= to_string(n);

        int len = str.size();
        int pivot=-1;
        for(int i= len-2;i>=0;i--){

            if(str[i]<str[i+1]){
                pivot =i;
                break;
            }
        }
        
        if (pivot == -1) {
            return -1 ;
        }

        for(int i=len-1;i>pivot;i--){
                
                if(str[i]>str[pivot]){
                    std::swap(str[pivot],str[i]);
                    break;
                }
        }

         std::reverse(str.begin() + pivot + 1,str.end());

         long long result = std::stoll(str);

         if (result > INT_MAX) {
    return -1;
}

     return static_cast<int>(result);
    }
};