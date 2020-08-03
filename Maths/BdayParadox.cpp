#include<bits/stdc++.h>

using namespace std;

int BdayParadox(float p) {
	if (p == 1.0)
		return 366
	int num = 365;
	int days = 365;

	int people = 1;

	float prob = 1;

	while (prob > 1-p) {
		prob *= (float)(num - 1)/(float)days;
		num--;
		people++;
	}
	return people;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	float p;
	cin>>p;

	cout<<BdayParadox(p)<<endl;
}

