#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--)
    {
        string s;
        cin>>s;
        stack<char> p;
        int ans=s.size();
        for (auto& c:s)
        {
            if(!p.empty() && p.top()==c){ 
                ans=1;
                break;
            }
            else p.push(c);
        }
        cout<<ans<<endl;
    }
}