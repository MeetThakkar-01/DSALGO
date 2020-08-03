/*

Mike found an interesting problem. In this problem you are given two integers, n and k. You need to find the the maximum value of x, such that, n! % kx = 0.
Input Format

First line contains number of test cases, T. Each test case contains two integers each, n and k.
Constraints

1<=T<=20 1<=n<=10^8 2<=k<=10^8
Output Format

Print the value of x for each test case.
Sample Input

2
5 2
1000 2

Sample Output

3
994

Explanation

In the first test case, n = 5 and k = 2. So, n! = 120. n! % 2^0 = 0, n! % 2^1 = 0, n! % 2^2 = 0, n! % 2^3 = 0, n! % 2^4 = 8, n! % 2^5 = 24, n! % 2^6 = 56, n! % 2^7 = 120. So, the answer should be 3.
*/


#include<iostream>
#include<vector>
#define INT_MAX 1000000000

using namespace std;

vector<pair<int, int>> primeFactors;

void pFactors(int k, int n){
	int ans = INT_MAX;
	for (int i = 2; i*i <= k; ++i)
	{
		if (k%i == 0){
			int count = 0;
			while(k%i == 0) {
				count ++;
				k = k/i;
			}
			int temp = 0;
			long long p = i;

			while(p<=n) {
				temp += n/p;
				p = p * i;
			}
			ans = min(ans, temp/count);
		}
	}
	if (k > 1) {
		long long p = k;
		int temp = 0;
		while(p<=n){
			temp += n/p;
			p = p*k;
		}
		ans = min(ans, temp);
	}

	if (ans == INT_MAX)
		ans = 0;

	cout<<ans<<endl;
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,k;
	cin>>n>>k;

	pFactors(k, n);


	
	return 0;
}