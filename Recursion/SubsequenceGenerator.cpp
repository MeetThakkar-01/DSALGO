#include<iostream>
#include<vector>

using namespace std;

void SubSequenceGenerator(char *in, char *out, int i, int j){

  if(in[i] == '\0'){
    out[j] = '\0';
    cout<<out<<endl;
    return;
  }

  // include current Char
  out[j] = in[i];
  SubSequenceGenerator(in, out, i + 1, j + 1);

  //exclude current Char 
  SubSequenceGenerator(in, out, i + 1, j);
  
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    char input[100];
    cin>>input;
    char output[100]; 

    SubSequenceGenerator(input, output, 0, 0);
    
    return 0;
}