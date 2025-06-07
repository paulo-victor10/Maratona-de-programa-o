#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n; //11

    // vector<vector<string>> matriz(n, vector<string>(n));
    string matriz[n][n];
    string black="#", white=".";

    for (int i = 1; i <= n; i++) //i=2
    {
        int j=n-i+1; //j=10
        if (i<=j) //2<=10
        {
            for (int l = i-1; l < j; l++)
            {
                for (int c = i-1; c < j; c++)
                {
                    if(i%2!=0) matriz[l][c]=black;
                    else matriz[l][c]=white;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
}