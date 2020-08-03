/*

Sameer and Arpit want to overcome their fear of Maths and so they have been recently practicing Maths problems a lot. Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored of problems involving factorials. Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.
Input

First line contains an integer T, the number of queries asked.

Next T lines contains T queries of the form “N P”. (quotes for clarity)
Output

Output exactly T lines, containing N! modulo P.
Example

Input:
3
2 5
5 11
21 71

Output:
2
10
6

Constraints:

1 <= T <= 1000

1 < P <= 2*10^9

1 <= N <= 2*10^9
Abs(N-P) <= 1000
*/
#include<iostream>
#include<vector>

using namespace std;

long long fastModPower(long long a, long long b, long long m) {
	if (b == 0){
		return 1;
	}

	long long res = 1;

	while(b!=0){
        if(b&1){
            res = (res * a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return res;
}

long long solve(long long n, long long p){
	long long ans = -1;

	for (long long i = n + 1; i <= p-1; ++i)
	{
		long long temp = fastModPower(i, p - 2, p);
        ans = (temp*ans)%p;
	}
	return (ans + p);
}



int main() {
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    
    long long t, n, p;
    cin>>t;

    while(t--){
    	cin>>n>>p;

    	if (p<=n){
    		cout<<0<<endl;
    	}

    	else{
    		cout<<solve(n, p)<<endl;
    	}

    }

    return 0;
}
