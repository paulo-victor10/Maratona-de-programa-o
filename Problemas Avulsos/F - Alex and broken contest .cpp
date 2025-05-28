#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int count(const string& frase, const string& palavra){
    int count = 0, pos=0;
    while ((pos = frase.find(palavra,pos)) != string::npos)
    {
        count++;
        pos+= palavra.length();
    }
    return count;
    
}

int main(){
    string frase;
    std::vector<string> nomes={"Danil", "Olya", "Slava", "Ann","Nikita"};
    int repetiu=0, achou=0;
    std::getline(cin, frase);

    for(int i=0;i<nomes.size();i++){
        if(frase.find(nomes[i])!=string::npos){
            if(achou){
                repetiu=1;
                break;
            }
            if(count(frase, nomes[i])>1){
                repetiu=1;
                break;
            }
            achou=1;
        }

    }
    if(repetiu){
        cout<<"NO"<<endl;
    }
    else if(!achou){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
    
}
