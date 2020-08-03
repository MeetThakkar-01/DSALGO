    
// C. Product of Three Numbers
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes
// input
// standard input
// output
// standard output

// You are given one integer number n
// . Find three distinct integers a,b,c such that 2≤a,b,c and a⋅b⋅c=n

// or say that it is impossible to do it.

// If there are several answers, you can print any.

// You have to answer t

// independent test cases.
// Input

// The first line of the input contains one integer t
// (1≤t≤100

// ) — the number of test cases.

// The next n
// lines describe test cases. The i-th test case is given on a new line as one integer n (2≤n≤109

// ).
// Output

// For each test case, print the answer on it. Print "NO" if it is impossible to represent n
// as a⋅b⋅c for some distinct integers a,b,c such that 2≤a,b,c

// .

// Otherwise, print "YES" and any possible such representation.

    #include<iostream>
    #include<vector>
    #define INT_MAX 1000000000

    using namespace std;

    int main() {
        #ifndef ONLINE_JUDGE
        	freopen("input.txt", "r", stdin);
        	freopen("output.txt", "w", stdout);
        #endif

        int t;
        cin>>t;
        while(t--){
            bool flag = false;
            vector<int> p;
            int n;
            cin>>n;
            int n1 = n;
            int FactorCount = 0;

            for (int i = 2; i*i <= n; ++i)
            {
                if(n%i == 0){
                    FactorCount++;
                    n /= i;
                    p.push_back(i);
                    }
                if (FactorCount == 2) {
                	p.push_back(n);
                	break;
                }
            }
            if(FactorCount<2)
            	cout<<"NO"<<endl;
            else if(p[2] == p[1] || p[2] == p[0])
            	cout<<"NO"<<endl;
            else{
            	cout<<"YES"<<endl;
            	cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
            }
        }
        return 0;
    }
            