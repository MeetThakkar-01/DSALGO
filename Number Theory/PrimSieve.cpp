#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;

const long long N = 1000000;

bool sieve[N];
vector<long long> primes;

long long calculateSieve(long long n){

    long long count;

    for (long long i = 0; i < N; ++i)
    {
        sieve[i] = 1;
    }

    sieve[0] = sieve[1] = 0;

    for (long long i = 2; i <= N; ++i)
    {
        if(sieve[i] == 1){
            primes.push_back(i);
            for (long long j = i; j <= N; j += i)
            {
                sieve[j] = 0;
            }
        }
    }

    for(long long i = 2;i <= n;i++){
        if(sieve[i]){
            count ++;
        }
    }

    return count;
    
}


int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif

    long long n, m;
    long long ans = 0;
    cin>>m>>n;
    
    int csum[N] = {0};
    for (int i = i; i < N; ++i)
    {
        csum[i] = csum[i - 1] + sieve[i];
    }

    ans = csum[n] - csum[m - 1];

    cout<<ans<<endl;

    
    return 0;
}
