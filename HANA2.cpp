#include<bits/stdc++.h>
using namespace std;
const long long BASE=1e7;
struct o
{
	long long yes,no;
} f[201][201];
int a[201][201],n,m;
void Input()
{
	cin>>m>>n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
}
void Process()
{
	Input();
	if (n<3 && m<3)
	{
		cout<<0;
		return;
	}
	f[1][2].no=(a[1][2]!=-1)?1:0;
	f[1][2].yes=0;
	for (int i=3;i<=n;i++)
	{
		if (a[1][i]==-1 || a[1][i-1]==-1)
		{
			f[1][i].no=0;
			f[1][i].yes=0;
			continue;
		}
		if (a[1][i]!=a[1][i-1])
		{
			f[1][i].yes+=(f[1][i-1].yes+f[1][i-1].no);
			f[1][i].no=0;
		}
		else
		{
			f[1][i].yes=f[1][i-1].yes;
			f[1][i].no=f[1][i-1].no;
		}
	}
	f[2][1].no=(a[2][1]!=-1)?1:0;
	f[2][1].yes=0;
	for (int i=3;i<=m;i++)
	{
		if (a[i][1]==-1 || a[i-1][1]==-1)
		{
			f[i][1].no=0;
			f[i][1].yes=0;
			continue;
		}
		if (a[i][1]!=a[i-1][1])
		{
			f[i][1].yes+=(f[i-1][1].yes+f[i-1][1].no);
			f[i][1].no=0;
		}
		else
		{
			f[i][1].yes=f[i-1][1].yes;
			f[i][1].no=f[i-1][1].no;
		}
	}
	for (int i=2;i<=m;i++)
		for (int j=2;j<=n;j++)
		{
			if (a[i][j]==-1)
			{
				f[i][j].yes=0;
				f[i][j].no=0;
				continue;
			}
			if (a[i-1][j]==a[i][j])
			{
				f[i][j].yes+=f[i-1][j].yes;
				f[i][j].no+=f[i-1][j].no;
				f[i][j].yes%=BASE;
				f[i][j].no%=BASE;
			}
			else
			{
				f[i][j].yes+=(f[i-1][j].no+f[i-1][j].yes);
				f[i][j].yes%=BASE;
			}
			if (a[i][j-1]==a[i][j])
			{
				f[i][j].yes+=f[i][j-1].yes;
				f[i][j].no+=f[i][j-1].no;
				f[i][j].yes%=BASE;
				f[i][j].no%=BASE;
			}
			else
			{
				f[i][j].yes+=(f[i][j-1].no+f[i][j-1].yes);
				f[i][j].yes%=BASE;
			}
		}
	long long res=(f[m-1][n].yes+f[m][n-1].yes)%BASE;
	cout<<res<<"\n";
}
void debug()
{
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++) cout<<f[i][j].yes<<"-"<<f[i][j].no<<"  ";
		cout<<"\n\n";
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	//debug();
	return 0;
}

