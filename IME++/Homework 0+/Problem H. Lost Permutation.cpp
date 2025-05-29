#include <bits/stdc++.h>
using ll=long long;
using namespace std;
//OBS: set pode ser bom para preencher lacunas numa sequencia que deve ir de 1 à n repetindo cada numero apenas 1 vez [1,2,3,4,5] 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,s;
        cin>>m>>s;
        set<int> b;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin>>x;
            b.insert(x);
        }

        int i=1;
        while(s>0){
            if(b.count(i)==0){ //add o que falta e subtrai de s
                s-=i;
                b.insert(i);
            }
            i++;
        }
        if(s==0){ //precisamos saber se a sequencia final vai de 1 até n (maior valor)
            bool ans=true;
            auto it=b.rbegin(); //aponta pro maior valor do set
            for(int i=1;i<=*it;i++){ 
                if(b.count(i)==0){
                    ans=false; //s zerou, mas o set nao vai de 1 até n
                    break;
                }
            }
            cout<<(ans? "YES\n":"NO\n");
        }
        else cout<<"NO\n";
    }
}