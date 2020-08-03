#include<bits/stdc++.h>

using namespace std;

long long power(long a, long n){
	// long ans = 1;
	if (n == 0)
		return 1;
	if (n == 1)
		return a;
	long long ans = power(a, n/2);
	if (n%2 != 0)
		ans = ans * ans * a;
	else
		ans = ans * ans;
	

	return ans;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long a, n;
	cin>>a>>n;
	cout<<power(a, n)<<endl;

	return 0;
}

