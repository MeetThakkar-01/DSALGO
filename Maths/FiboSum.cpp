#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
using namespace std;

void multiply(long long A[2][2], long long B[2][2]){
	long long first = ((A[0][0]*B[0][0] % mod) + (A[0][1]*B[1][0] % mod)) % mod;
	long long second = ((A[0][0]*B[1][0] % mod) + (A[0][1]*B[1][1] % mod)) % mod;
	long long third = ((A[1][0]*B[0][0] % mod) + (A[1][1]*B[1][0] % mod)) % mod;
	long long fourth = ((A[1][0]*B[0][1] % mod) + (A[1][1]*B[1][1] % mod)) % mod;

	A[0][0] = first;
	A[0][1] = second;
	A[1][0] = third;
	A[1][1] = fourth;
}

void power(long long A[2][2], long long n) {
	if(n==0 || n==1) {
		return;
	}
	power(A, (int)n/2);

	multiply(A, A);

	if ((n%2) != 0) {
		long long t[2][2] = {{1, 1}, {1, 0}};
		multiply(A, t);
	}

}

long long fibo(long long n) {
	long long A[2][2] = {{1, 1}, {1, 0}};
	if (n == 0){
		return 0;
	}

	power(A, n-1);

	return A[0][0];
}


int main() {
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

	int t;
	cin>>t;
	while(t--){
		long long n, m;
		cin>>n>>m;
		cout<<fibo(m + 2) - fibo(n + 1)<<endl;
	}
	return 0;
}