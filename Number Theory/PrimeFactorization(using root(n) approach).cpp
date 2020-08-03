#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> primeFactors;

void pFactors(int n){
	for (int i = 2; i*i <= n; ++i)
	{
		if (n%i == 0){
			int count = 0;
			while(n%i == 0) {
				count ++;
				n = n/i;
			}
			primeFactors.push_back(make_pair(i, count));
		}
	}
	if (n!=1) {
		primeFactors.push_back(make_pair(n, 1));
	}

	for(auto x : primeFactors) {
		cout<<x.first<<"^"<<x.second<<endl;
	}
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	pFactors(n);
	
	return 0;
}