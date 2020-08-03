// Hänschen dreams he is in a shop with an infinite amount of marbles. He is allowed to select n marbles. There are marbles of k different colors. From each color, there are also infinitely many marbles. Hänschen wants to have at least one marble of each color, but still there are a lot of possibilities for his selection. In his effort to make a decision he wakes up. Now he asks you how many possibilities for his selection he would have had. Assume that marbles of equal color can't be distinguished, and the order of the marbles is irrelevant.
// Stars And Bars Combinaotricks

#include<bits/stdc++.h>
using namespace std;
  
long long int ncr(long long int n, long long int r) 
{ 
	long long int ans = 1;
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
	long long int t, k, n;
	cin>>t;
	while(t--) {
		cin>>n>>k;

		cout<<ncr(n-1, k-1)<<endl;
	}
	
}

