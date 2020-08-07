#include<iostream>
#include<vector>

using namespace std;

void balancedBracketsGenerator(char *out, int n, int i, int open, int close){

  if(i == 2*n){
    out[i] = '\0';
    cout<<out<<endl;
    return;
  }

  if (open < n){
    out[i] = '(';
    balancedBracketsGenerator(out, n, i + 1, open + 1, close);
  }

  if(open > close){
    out[i] = ')';
    balancedBracketsGenerator(out, n, i + 1, open, close + 1);
  }
  
  
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    char output[1000]; 

    balancedBracketsGenerator(output, n, 0, 0, 0);
    
    return 0;
}