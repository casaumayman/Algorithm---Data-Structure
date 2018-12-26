#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001];
int pos[100000];
void Input(){
    cin>>n>>k;
    int x;
    for (int i=1;i<=n;i++){
        cin>>x;
        a[i] = (a[i-1]+x) % k;
        if (a[i] && !pos[a[i]]) pos[a[i]] = i;
    }
}
void Process(){
    Input();
    int maxs = 0;
    for (int i=1;i<=n;i++)
        if ((!a[i] || (a[i] && pos[a[i]])) && (maxs < i - pos[a[i]])){
            maxs = i - pos[a[i]];
        }
    cout<<maxs;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    Process();
    return 0;
}
