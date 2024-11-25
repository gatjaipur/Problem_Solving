// Reverse digits of an integer.

// Example1:

// x = 123,

// return 321
// Example2:

// x = -123,

// return -321

// Return 0 if the result overflows and does not fit in a 32 bit signed integer

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
