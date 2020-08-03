#include<iostream>
#include<map>
#define MOD 1000000007
#define ll long long
using namespace std;

ll modFastExpo(ll a, ll p){
    if (p == 0){
        return 1;
    }
    a = a % p;
    ll res = 1;

    while(p > 0){
        if(p&1){
            res = (res * a);
            res %= MOD;
        }

        a = (a * a);
        a %= MOD;
        p = p >> 1;
    }
    return (res + MOD)%MOD; 
}

ll factMod(ll n){

    ll nFact = 1;
    for (ll i = 1; i <= n; ++i)
    {
        nFact = (nFact * i)%MOD;
    }

    return nFact;

}

ll fastNcR(ll n, ll r){

    ll result;

    ll nFact = factMod(n);

    ll t1 = factMod(r);

    ll rFactinv = modFastExpo(t1, 1000000007 - 2);

    ll t2 = factMod(n - r);

    ll nrFactinv = modFastExpo(t2, 1000000007 - 2);

    result = (nFact * rFactinv);
    result %= MOD;

    result = (result * nrFactinv);
    result %= MOD;

    return result;
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    ll n, r;
    cin>>n>>r;

    cout<<fastNcR(n, r);

    return 0;
}