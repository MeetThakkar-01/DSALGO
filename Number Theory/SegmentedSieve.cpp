#include<iostream>
#include<vector>
using namespace std;

const int N = 100000;

int p[N + 1];
vector<int> primes;

void sieve() {
    for (int i = 0; i < N; i++)
    {
        p[i] = 0;
    }
    for(long long i = 2; i<=N;i++){
        if(p[i]==0){
            primes.push_back(i);
            for (long long j = i*i; j<=N; j+=i)
            {
                p[j] = 1;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    sieve();

    int t;
    cin>>t;

    while(t--) {
        long long n, m;
        cin>>m>>n;

        bool segment[n - m + 1];
        for (int i = 0; i < n-m+1; ++i)
        {
            segment[i] = 0;
        }

        for(auto x: primes) {
            // stop Looping after reaching till Root Of (n)
            if(x*x > n){
                break;
            }
            // start is the initial number in segmented range which is divisible by X
            int start = (m/x) * x;
            // prime number lies in Segmented Sieve range so start will be the next multiple of x 
            if (x>=m && x<=n) {
                start = 2*x;
            }
            // marking all multiples of x as NOT PRIME in range Start.....n
            for (int i = start; i <= n; i+=x)
            {
                segment[i - m] = 1;
            }
        }
        // Loop over range m....n and print primes
        for (int i = m; i <= n; ++i)
        {
            if (segment[i - m] == 0 && i!=1) {
                cout<<i<<endl;
            }       
        }
        cout<<endl;

    }
    
    return 0;
}