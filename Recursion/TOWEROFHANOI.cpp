#include<iostream>
#include<vector>

using namespace std;

void solve(int n, char src, char destination, char helper){
  if (n == 0){
    return;
  }

  solve(n - 1, src, helper, destination);
  cout<<"MOVE DISK "<<n<<" FROM "<<src<<" TO "<<destination<<endl;
  solve(n - 1, helper, destination, src);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve(3, 'A', 'C', 'B');
    
    return 0;
}