/*

Alice is given the task of finding totient φ of a positive integer n (the number of positive integers less than or equal to n that are co-prime to n). As Alice is going on a date, he asks you to write a program for this.
Input Format

First line of input of consists of an integer 't' denoting the number of test cases. Then 't' lines follow each containing integer values 'n' to calculate totient.
Constraints

1<=t<=50000 1<=n<=10^6
Output Format

Print 't' lines
Sample Input

2
2
3

Sample Output

1
2

Explanation

For first test case: number co-prime to 2 which are less than 2 is '1' only.
*/

#include<iostream>
#include<map>
#define MOD 1000000007
using namespace std;

int totient[1000001];

bool isprime(long long n){
    if(n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    if(n%2 == 0){
        return false;
    }
    for(long long i=3 ; i*i<=n ; i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void calcTotient(){

    int n = 1000001;

    for (int i = 0; i < 1000001; ++i)
    {
        totient[i] = i;
    }

    for (int i = 2; i <= n  ; ++i)
        {
            if(isprime(i)){
                 for(int j=i ; j<=1000001 ; j+=i){
                    totient[j] *= (i-1);
                    totient[j] /= i;
                 }
            }
        }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    calcTotient();
    long long t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        cout<<totient[n]<<endl;
    }

    return 0;
}