#include <bits/stdc++.h>

using namespace std;

bool ePrimo(int n){
    if (n==1){return false;}
    if (n==2){return true;}
    for (int i = 2; i <=sqrt(n); i++)
    {
        if (n%i==0){return false;} 
    }
    return true;
}

int main(){
    /* V pensa em um número x que está entre 1 e n
    P tem que advinhar o numero 
    P pergunta se o x (target) é divisivel por y
    */

   int n;
   cin>>n;
   vector<int>a,v;
   //for pra criar um vetor de primos:
   for (int i = 2; i <=n; i++)
   {
    if (ePrimo(i)) {a.push_back(i);} 
   }
   for (int i = 0; i < a.size(); i++)
   {
    v.push_back(a[i]);
    int x=a[i];
    x*=x;
    while (x<=n)
    {
        v.push_back(x);
        x*=a[i];
        }
   }
    cout<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
