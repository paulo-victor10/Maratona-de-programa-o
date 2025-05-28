#include <bits/stdc++.h>

using namespace std;

int main(){
    int n=5;
    int arr[5];
    for (int i = 0; i < 5; i++) {cin>>arr[i];}
    while (n--) {if (!arr[n-1]) cout<<n;}
}