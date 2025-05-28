#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    bool ans=false;
    cin >> x >> y;

    for (int i = 0; i <= 100; i++)
    {
        int a=x-i;
        if(a>=0){
            if(i*2 + a*4==y){
                ans=true;
                break;
            }
        }
    }
    cout<<(ans ? "Yes":"No");
}