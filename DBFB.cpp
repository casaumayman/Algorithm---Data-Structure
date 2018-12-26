#include<bits/stdc++.h>
using namespace std;
const long long BASE=1e9+7;
struct ST
{
	long long a1,a2;
	ST()
	{
		a1=0;
		a2=0;
	}
};
ST f[100001];
int n,m,T;
void Khoi_Tao()
{
	f[1].a1=1;
	f[1].a2=0;
	f[2].a1=0;
	f[2].a2=1;
	for (int i=3;i<=100000;i++)
	{
		f[i].a1=((f[i-1].a1%BASE)+(f[i-2].a1%BASE))%BASE;
		f[i].a2=((f[i-1].a2%BASE)+(f[i-2].a2%BASE))%BASE;
	}
}
void Process()
{
	cin>>m>>n;
	long long x;
	long long res=0;
	for (int i=1;i<=m;i++)
	{
		cin>>x;
		res+=((f[n].a1*m)%BASE*x)%BASE;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>x;
		res+=((f[n].a2*m)%BASE*x)%BASE;
	}
	cout<<res%BASE<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Khoi_Tao();
	cin>>T;
	while (T--) Process();
	return 0;
}

