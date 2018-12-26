#include<bits/stdc++.h>
using namespace std;
bool a[1001][1001];
int row[1001],column[1001],sl,dem,m,n;
void Input()
{
	cin>>m>>n;
	char c;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
		{
			cin>>c;
			a[i][j]=(c=='#')?true:false;
			if (c=='#')
			{
				sl++;
				row[i]++;
				column[j]++;
			}
		}
}
int maxr()
{
	int maxs=0;
	for (int i=1;i<=m;i++)
		if (row[i]>row[maxs]) maxs=i;
	return maxs;
}
int maxc()
{
	int maxs=0;
	for (int i=1;i<=n;i++)
		if (column[i]>column[maxs]) maxs=i;
	return maxs;
}
void updater(int i)
{
	row[i]=0;
	for (int j=1;j<=n;j++)
		if (a[i][j])
		{
			sl--;
			column[j]--;
			a[i][j]=false;
		}
}
void updatec(int j)
{
	column[j]=0;
	for (int i=1;i<=m;i++)
		if (a[i][j])
		{
			sl--;
			row[i]--;
			a[i][j]=false;
		}
}
void Process()
{
	Input();
	int maxs,a,b;
	bool maxrow;
	while (sl)
	{
		a=maxr();
		b=maxc();
		if (row[a]>column[b])
		{
			maxs=a;
			maxrow=true;
		}
		else
		{
			maxs=b;
			maxrow=false;
		}
		dem++;
		if (maxrow) updater(maxs);
		else updatec(maxs);
	}
	cout<<dem;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
