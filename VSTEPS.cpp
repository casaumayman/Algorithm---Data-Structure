#include<bits/stdc++.h>
using namespace std;
const int BASE=14062008;
int n,k,f[100001];
bool a[100001];
void Process()
{
	cin>>n>>k;
	int x;
	for (int i=1;i<=k;i++)
	{
		cin>>x;
		a[x]=true;
	}
	f[1]=1;
	f[2]=a[2]?0:1;
	for (int i=3;i<=n;i++)
		if (a[i]) f[i]=0;
		else f[i]=(f[i-1]+f[i-2])%BASE;
	cout<<f[n];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
