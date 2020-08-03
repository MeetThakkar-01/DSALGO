// Mike has got an array A of n numbers where binary representations of two consecutive numbers differ by only one bit. Now, he has a problem for you. He wants you to tell if there exists four numbers A[i1],A[ i2], A[i3],A[ i4] such that xor of these numbers is equal to 0. You can find this problem here.


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long arr[100000] = {0};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	long n;
	bool flag = false;
	cin>>n;

	for (long i=0;i<n;i++){

		cin>>arr[i];
	}

	if (n>69) {
		cout<<"YES"<<endl;
		return 0;
	}

	for (long i=0;i<n;i++){
		for(long j=i+1;j<n;j++){
			for(long k=j+1;k<n;k++){
				for(long l=k+1;l<n;l++){
					if ((arr[i]^arr[j]^arr[k]^arr[l]) == 0){
						cout<<"YES"<<endl;
						return 0;
					}
				}
			}
		}
	}

	cout<<"NO"<<endl;

	return 0;
}

