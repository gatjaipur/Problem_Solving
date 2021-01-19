class Solution {
public:
    int lengthOfLastWord(string s) {
        int len =0;
        int n = s.length();
        bool lastChar = false;
        for(int i= n-1; i>=0; i--) {
            char ch = s[i];
            if(ch != ' ') {
                lastChar = true;
                len++;
            } else {
                if(lastChar) {
                    break;
                }
            }
            
        }
        return len;
    }
};
