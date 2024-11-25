// Determine whether an integer is a palindrome. Do this without extra space.

// A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
// Negative numbers are not palindromic.

// Input : 12121
// Output : True

// Input : 123
// Output : False


int Solution::reverse(int A) {
    long res = 0;
    
    int sign = 1;
    
    if(A<0) {
        sign = -1;
        A*= -1;
    }
    
    while(A>0){
        int mod = A%10;
        
        A/=10;
        
        if(sign*A > INT_MAX/10 || (sign*A==INT_MAX/10 && mod > 7)) {
            return 0;
        }
        
        if(sign*A < INT_MIN/10 || sign*A==INT_MIN/10 && mod < -8) {
            return 0;
        }
        res = res*10 + mod;
        
    }
    
    if(sign*res > INT_MAX || sign*res < INT_MIN) {
        return 0;
    }
    return (int)sign*res;
}

int Solution::isPalindrome(int A) {
    if(A <0) {
        return 0;
    }
    
    return (reverse(A) == A);
}


// //Method 2 Two Pointer Method

// int Solution::isPalindrome(int A) {
//     string s=to_string(A);
//     for(int i=0;i<s.length();i++){
//         if(s[i]!=s[s.length()-1-i]){
//             return false;
//         }
//     }
//     return true;
// }