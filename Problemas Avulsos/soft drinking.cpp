#include <bits/stdc++.h>

using namespace std;

int main(){
    // n amigos com frio
    //k garrafas para se aquecer
    // l mL que cada garrafa tem
    // c limões cortados em d fatias
    // p gramas de sal
    // cada amigo preciso de nl mililitros para fazer o brinde, uma fatia de limão e np gramas de sal
    //precisa fazer o máximo de brindes possíveis
    //todos bebem a mesma quantidade}

    // QUANTOS BRINDES CADA AMIGO PODE FAZER
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int t1=(k*l)/nl; //total de brindes
    int t2=c*d; //total de fatias de limão que eles tem
    int t3=p/np; // quanto sal dá pra colocar por drink

    int minimo;
    minimo=min(t1,min(t2,t3))/n;
    cout<<minimo;
}