// Replace 'pi' with '3.14' in a string


#include<iostream>
using namespace std;

void replacePi(char a[], int i) {
    if (a[i] == '\0' or a[i + 1] == '\0'){
        return;
    }
    if(a[i] == 'p' and a[i + 1] == 'i'){
        // shift and replace with 3.14
        int j = i + 2;
        while(a[j]!='\0'){
            j++;
        }
        while(j >= i + 2) {
            a[j + 2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4'; 
    }
    replacePi(a, i + 1);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    char a[1000];
    cin>>a;

    replacePi(a, 0);

    cout<<a<<endl;

    return 0;
}