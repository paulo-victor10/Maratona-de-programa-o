#include <bits/stdc++.h>
#include <vector>;
using namespace std;

int main(){
    int n;
    cin>>n;
    int vetor[n];
    for(int i=0; i<n;i++){
        cin>>vetor[i];
    }
    sort(vetor,vetor+n);
    
    int  checar=0;
    
    for(int i=1; i<n;i++){
        if(vetor[i]>vetor[0]){
            cout<<vetor[i]<<endl;
            checar=1;
            break;
        }
    }
    if(!checar){
        cout<<"NO"<<endl;
    }
}