#include<bits/stdc++.h>
using namespace std;
#define MAX_INT 10000000
#define ll long long 
  
unsigned long long int ncr(unsigned long long int n, unsigned long long int r) 
	{ 
		unsigned long long int ans = 1;
		if (r > n-r){
			r = n - r;
		}
		
		for(auto i=1;i<=r;i++)
			ans *= (n-i+1), ans /= i;

		return ans; 
	}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif


	unsigned long long int n;
	cin>>n;

	unsigned long long int c = ncr(2*n, n);

	cout<<c/(n + 1)<<endl;

	return 0;
}

