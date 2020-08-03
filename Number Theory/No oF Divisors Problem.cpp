#include<iostream>
#include<map>
#define MOD 1000000007
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, q, k;
    cin>>n;
    int count[100000];
    int sum[100000];
    for (int i = 0; i < 100000; ++i)
    {
        count[i] = sum[i] = 0;
    }
    for (int i = 0; i < q; ++i)
    {
        int temp;
        cin>>temp;

        count[temp]++;
    }

    for (int i = 2; i < n; ++i)
    {
        for (int j = i; j < n; j+=i)
        {
            sum[i] += count[j];
        }
    }


    cout<<sum[k];

    return 0;
}