#include <bits/stdc++.h>
using namespace std;
int f[5001][5001];
string s,t;
int main() {
    cin>>s>>t;
    for (int i=1;i<=s.size();i++)
        for (int j=1;j<=t.size();j++)
            if (s[i-1]==t[j-1]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
    cout<<f[s.size()][t.size()];
    return 0;
}
