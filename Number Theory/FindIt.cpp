/*

You are given N numbers.
Now you have Q queries.
For each query you will be given an integer K.
You have to find out the number of multiples of K among the given N numbers.
Input Format

The first line consists of number N.
Next N line contains N numbers. Next line contains number of queries Q. Next Q lines contains Integer K for each query
Constraints

1 <= N <= 10^5 1 <= numbers <= 10^5 1 <= Q <= 10^5 1 <= K <= 10^5
Output Format

Output Q lines the answer for every query.
Sample Input

4
5
8
10
8
1
2

Sample Output

3

*/

#include<iostream>
#include<map>
#define MOD 1000000007
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin>>n;
    int count[100001];
    int sum[100001];
    for (int i = 0; i < 100001; ++i)
    {
        count[i] = sum[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin>>temp;

        count[temp]++;
    }

    sum[0] = 0; sum[1] = n;

    for (int i = 2; i < 100001; ++i)
    {
        for (int j = i; j < 100001; j+=i)
        {
            sum[i] += count[j];
        }
    }


   cin>>q;



   while(q--){
       int k;
       cin>>k;
       cout<<sum[k]<<endl;
   }

    return 0;
}