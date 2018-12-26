#include<bits/stdc++.h>
using namespace std;
const int BASE = 1e6;
int n,k,f[1001];
void Process(){
    cin>>n>>k;
    f[0] = 1;
    for (int i=1;i<=k+1;i++) f[i] = i+1;
    for (int i=k+1;i<=n;i++) f[i] = (f[i-1] + f[i-k-1]);
    cout<<f[n];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
