class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        unsigned int len = s.size();
        for(int i = len/2; i>0; i--){
            if(len % i == 0){
                string s0 = s.substr(0,i);
                int j=1;
                for(; j<(len/i); j++){
                    if(s0 != s.substr(j*i,i)){
                        break;
                    }
                } 
                if(j==len/i) return true;
            }
        } 
        return false;
    }
};