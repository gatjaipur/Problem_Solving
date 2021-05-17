// Given 2 non negative integers m and n, find gcd(m, n)

// GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
// Both m and n fit in a 32 bit signed integer.

// Example

// m : 6
// n : 9

// GCD(m, n) : 3 

//Method 1

int Solution::gcd(int A, int B) {
while(B>0)
{
    int c=A%B;
    A=B;
    B=c;
}
    return A;
}

//Method 2

// int Solution::gcd(int A, int B) {
//     if(A < B) {
//         swap(A, B);
//     }
//     if(B == 0){
//         return A;
//     } else {
//         return gcd(B, A%B);
//     }
// }