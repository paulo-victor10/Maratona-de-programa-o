#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    vector<char> assentos(34, '#');
    for (int i = 0; i < k; ++i)
    {
        assentos[i] = 'O';
    }

    printf("+------------------------+\n");


    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|D|)\n", assentos[0],assentos[4],assentos[7],assentos[10],assentos[13],assentos[16],assentos[19],assentos[22],assentos[25],assentos[28],assentos[31]);
    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|.|\n", assentos[1],assentos[5],assentos[8],assentos[11],assentos[14],assentos[17],assentos[20],assentos[23],assentos[26],assentos[29],assentos[32]);
    printf("|%c.......................|\n",assentos[2]);
    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|.|)\n",assentos[3],assentos[6],assentos[9],assentos[12],assentos[15],assentos[18],assentos[21],assentos[24],assentos[27],assentos[30],assentos[33]);


    printf("+------------------------+\n");
}
