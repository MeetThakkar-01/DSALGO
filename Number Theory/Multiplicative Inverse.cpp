

// Given a number n. Print the multiplicative inverse of “n modulo 1000000007” .
// Input Format

// Single line containing an integer value.
// Constraints

// 1<=n<=1000000
// Output Format

// Integral value representing the multiplicative inverse.
// Sample Input

// 3

// Sample Output

// 333333336



#include<iostream>
#include<vector>
#define MOD 1000000007

using namespace std;
// Fast Modulo Exponentiaotion(Iterative)
long long modInverse(long long a, long long n){
    if (n == 0){
        return 1;
    }
    long long res = 1;
    while(n!=0){
        if(n&1){
            res = (res * a)%MOD;
        }
        a = (a*a)%MOD;
        n=n>>1;
    }

    return res;

}



int main() {
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    long long n;
    cin>>n;

    cout<<modInverse(n, MOD - 2)<<endl;

    return 0;
}
