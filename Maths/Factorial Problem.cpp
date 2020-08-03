// Mike found an interesting problem. In this problem you are given two integers, n and k. You need to find the the maximum value of x, such that, n! % kx = 0.


#include<bits/stdc++.h>
using namespace std;
#define MAX_INT 10000000
#define ll long long 
  

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int t, n, k;
	cin>>t;

	while(t--){
		ll occ, count, p;
		cin>>n>>k;

		ll ans = MAX_INT;

		for(int i=2;i*i<=k;i++){
			if(k%i == 0){
				occ = 0;
				while(k%i == 0){
					occ++;
					k = k/i;
				}
				count = 0;
				p = i;
				while(n/p >= 1) {

					count += n/p;
					p *= i;

				}
				ans = min(ans, count/occ);
			}	
		}

		if(k > 1) {
			count = 0;
			p = k;

			while(n/p >= 1) {
				count += n/p;
				p *= k;
			}
			ans = min(ans, count/1);

		}

		if (ans == INT_MAX) {
			ans = 0;
		}

		cout<<ans<<endl;
		return 0;
	}	
}

