#include <bits/stdc++.h>

using namespace std;

void setProbabilidade(string tipo, double &a, double &b, double &o){ 
    //recebe o tipo sanguineo e os genes
    if (tipo=="A")
    {
        a=0.75, b=0.0, o=0.25;
    }
    if (tipo=="B")
    {
        a=0.0, b=0.75, o=0.25;
    }
    if (tipo=="O")
    {
        a=0.0, b=0.0, o=1.0;
    }
    if (tipo=="AB")
    {
        a=0.5, b=0.5, o=0.0;
    }
}

int main(){
    string m1,m2,p1,p2; //tipos snaguineos avós maternos e paternos
    cin>>m1>>m2>>p1>>p2;

    //probabilidades de passar os genes dos avós para pais e maes
    double pA_m1, pB_m1, pO_m1;
    double pA_m2, pB_m2, pO_m2;
    double pA_p1, pB_p1, pO_p1;
    double pA_p2, pB_p2, pO_p2;


    setProbabilidade(m1, pA_m1,pB_m1,pO_m1);
    setProbabilidade(m2, pA_m2,pB_m2,pO_m2);
    setProbabilidade(p1, pA_p1,pB_p1,pO_p1);
    setProbabilidade(p2, pA_p2,pB_p2,pO_p2);

    //probabilidades de passar os genes dos pais para os filmes
    double pA_mae, pB_mae, pO_mae;
    double pA_pai, pB_pai, pO_pai;

    pA_mae=(pA_m1+pA_m2)/2.0;
    pB_mae=(pB_m1+pB_m2)/2.0;
    pO_mae=(pO_m1+pO_m2)/2.0;

    pA_pai=(pA_p1+pA_p2)/2.0;
    pB_pai=(pB_p1+pB_p2)/2.0;
    pO_pai=(pO_p1+pO_p2)/2.0;

    //probabilidade do filho ter um tipo sanguineo com base nos genes recebidos dos pais
    double pA_filho=pA_mae*pA_pai + pA_mae*pO_pai + pO_mae*pA_pai;
    double pB_filho=pB_mae*pB_pai + pB_mae*pO_pai + pO_mae*pB_pai;
    double pO_filho=pO_mae*pO_pai;
    double pAB_filho=pA_mae*pB_pai + pB_mae*pA_pai;

    cout << fixed << setprecision(2);
    cout<<pA_filho<<" "<<pB_filho<<" "<<pAB_filho<<" "<<pO_filho;
}