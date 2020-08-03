// MAtrix Multiplication Problem OF SPOJ
// Link : https://www.spoj.com/problems/SEQ/


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define ll long long
#define MOD 1000000000

using namespace std;

ll k;
vector<ll> b;
vector<ll> c;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B) {
	vector<vector<ll>>C(k + 1, vector<ll>(k + 1));

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			for (int x = 1; x <= k; x++)
			{
				C[i][j] = (C[i][j] + (A[i][x] * B[x][j])%MOD) % MOD;
			}
		}
	}
	return C;
}

vector<vector<ll>> power(vector<vector<ll>>A, ll p){
	if (p == 1){
		return A;
	}

	if(p&1){
		return multiply(A, power(A, p-1));
	}
	vector<vector<ll>> temp = power(A, p/2);
	return multiply(temp, temp);
}

ll compute(ll n) {
	if (n == 0)
		return 0;
	if (n <= k)
		return b[n - 1];

	// Declare function F1
	vector<ll> F1(k + 1);

	for (int i = 1; i <=k ; i++)
	{
		F1[i] = b[i - 1];
	}

	//Define Transformation MAtrix T
	vector<vector<ll>> T(k+1, vector<ll>(k + 1));

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i < k) {
				if (j == i+1)
					T[i][j] = 1;
				else
					T[i][j] = 0;
			}
			else{
				T[i][j] = c[k - j];
			}
		}
	}

	// find power of Transformation Matrix
	T = power(T, n - 1);
	ll ans = 0;

	for (int i = 1; i <= k; i++)
	{
		ans = (ans + (T[1][i]*F1[i])%MOD)%MOD;
	}

	return ans;
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll t, num, n;
	cin>>t;

	while(t--){
		cin>>k;

		for(int i=0;i<k;i++){
			cin>>num;
			b.push_back(num);
		}

		for(int i=0;i<k;i++){
			cin>>num;
			c.push_back(num);
		}

		cin>>n;

		cout<<compute(n)<<endl;

		b.clear();
		c.clear();

	}

	return 0;
}

