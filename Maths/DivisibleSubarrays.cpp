// You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
// A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.

// 1<=T<=10
// 1<=N<=10^5
// |ai|<=10^9


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long long arr[100000] = {0};
long long Cumarr[100000] = {0};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		long long count[n] = {0};

		long long ans = 0;
		long long sum = 0;

		for (int i=0;i<n;i++){
			cin>>arr[i];
			sum += arr[i] % n;
			sum = (sum + n) % n;
			count[sum]++;
		}
		ans += count[0] * (count[0] + 1)/2;
		for (int i=1;i<n;i++){
			// cout<<count[i];
			if (count[i] >= 2) {
				ans += count[i] * (count[i] - 1)/2;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}

