
// Almost primes Question(CodeForces)

#include<iostream>
#include<vector>

using namespace std;

const int N = 100000;

int p[N];
vector<int> primes;

void sieve() {
	for (int i = 0; i < 100000; ++i)
	{
		p[i] = 0;
	}
	for(long long i = 2; i<=N;i++){
		if(p[i]==0){
			primes.push_back(i);
			for (long long j = i; j<=N; j+=i)
			{
				p[j]++;
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

	int n;
	int ans = 0;
	cin>>n;

	for (int i = 2; i <=n; ++i)
	{
		// cout<<p[i];
		if (p[i] == 2) ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}