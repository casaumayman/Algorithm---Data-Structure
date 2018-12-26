#include<bits/stdc++.h>
using namespace std;
int n,a[101],f[101];
void Process()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f[1]=a[1];
	f[2]=a[2];
	f[3]=f[1]+f[2]+a[3];
	for (int i=4;i<=n;i++) f[i]=min(f[i-2]+(a[2]<<1)+a[1],f[i-1]+a[1])+a[i];
	//for (int i=1;i<=n;i++) cout<<f[i]<<" ";
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

