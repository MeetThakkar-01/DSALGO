#include<iostream>
#include<vector>

using namespace std;

int profit(int n, int c, int *wt, int *price){
  if(c == 0 or n == 0){
    return 0;
  }

  int ans = 0;
  int inc, exc;
  inc = exc = 0;

  if (wt[n - 1] <= c){
    inc = price[n - 1] + profit(n - 1, c - wt[n - 1], wt, price);
  }
  exc = profit(n - 1, c, wt, price);

  ans = max(inc, exc);

  return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int weights[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100}; 

    cout<<profit(4, 7, weights, prices)<<endl;
    
    return 0;
}