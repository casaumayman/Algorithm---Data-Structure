#include<bits/stdc++.h>
using namespace std;
int n,k,f[6701],a[6701];
void Process()
{
	cin>>n>>k;
	int t;
	for (int i=1;i<=n;i++){
		cin>>t;
		a[i]=a[i-1]+t;
	}
	if (k==1) {
        cout<<0;
        return;
	}
	for (int i=1;i<k;i++) f[i]=a[i];
	for (int i=k;i<=n;i++){
		for (int j=i-k+1;j<=i;j++){
            t = f[j-1] + (a[i] - a[j]);
            if (t > f[i]) f[i] = t;
		}
        //cout<<i<<":"<<f[i]<<"\n";
	}
	cout<<f[n];
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}
