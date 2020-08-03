
// You are given an array a consisting of n positive integers. You pick two integer numbers l and r from 1 to n, inclusive (numbers are picked randomly, equiprobably and independently). If l > r, then you swap values of l and r. You have to calculate the expected value of the number of unique elements in segment of the array from index l to index r, inclusive (1-indexed).
// Link : https://codeforces.com/problemset/problem/846/F

#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
#define MAX_INT 10000000
#define ll long long 

int arr[1000000] = {0};
int lastOcc[1000000] = {0};
int ans[1000000] = {0};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	// memset(lastOcc, 0, sizeof(lastOcc));
	// memset(arr, 0, sizeof(arr));
	// memset(ans, 0, sizeof(ans));

	for(auto i = 1; i<=n; i++) {
		cin>>arr[i];
	}

	double sum = 0.0;

	for(auto i = 1; i<=n; i++) {
		ans[i] = ans[i - 1] + (i - lastOcc[arr[i]]);
		lastOcc[arr[i]] = i;

		sum += ans[i];
	}

	double finalAns = 0.0;

	finalAns = (2*(sum) - n)/(n*n*1.0);

	cout<<fixed<<setprecision(6)<<finalAns<<endl;
	return 0;
}

