// Prime Or Not For Very Large Numbers Using Sieve

#include<iostream>
#include<vector>

using namespace std;

const int N = 100000;

int p[N] = {1};
vector<int> primes;

void sieve() {
	for (int i = 0; i < N; ++i)
	{
		p[i] = 1;
	}
	for(long long i = 2; i<=N;i++){
		if(p[i]==1){
			primes.push_back(i);
			for (long long j = i*i; j<=N; j+=i)
			{
				p[j] = 0;
			}
		}
	}
	p[2] = 1;
	p[0] = p[1] = 0;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	sieve();

	// for (int i = 2; i <= 10; ++i)
	// {
	// 	if (p[i])
	// 		cout<<i<<endl;
	// }

	long long n;
	bool flag = false;
	cin>>n;

	for (long long int i = 2; i*i <= n; ++i)
	{
		
		if(p[i] == 1){
			if (n % i == 0) {
				cout<<"Not Prime ";
				flag = true;
				break;
			}
		}
	}
	if (flag == false)
		cout<<"YES it is Prime ";
	
	return 0;
}