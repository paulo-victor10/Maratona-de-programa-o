#include <bits/stdc++.h>

using namespace std;

int main(){
   int n,k;
   cin>>n>>k;
   string s;
   cin>>s;

   deque<char> dq(s.begin(),s.end());

   for (int i = 0; i < n and k>0; i++)
   {
    if (dq[i]=='.')
    {
        dq.erase(dq.begin()+i);
        dq.push_front('.');
        k--;
    }
    
   }

   string ans(dq.begin(),dq.end());

   cout<<ans;
   
   
}