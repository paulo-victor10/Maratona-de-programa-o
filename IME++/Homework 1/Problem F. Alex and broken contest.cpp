#include <bits/stdc++.h>

using namespace std;

int count(string frase, string target){
    int a=0,size=target.size(),pos,c=0;
    while((pos=frase.find(target,a))>=0){
        a=a+pos+size;
        c++;
    }
    return c;
}

int main(){
    string s;
    int ans=0;
    cin>>s;
    vector<string> friends={"Danil", "Olya", "Slava", "Ann", "Nikita"};
    for (int i = 0; i < 5; i++)
    {
        ans+=count(s,friends[i]);
    }
    if(ans==1) cout<<"YES";
    else cout<<"NO";
}