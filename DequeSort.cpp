#include<bits/stdc++.h>
using namespace std;
int n,f[1000001];
void Process(){
    cin>>n;
    int x, maxs = 0;
    for (int i=1;i<=n;i++){
        cin>>x;
        f[x] = f[x-1] + 1;
        if (f[x] > maxs) maxs = f[x];
    }
    cout<<n - maxs;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
