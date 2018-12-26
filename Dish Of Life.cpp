#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[100001];
vector <int> vec[100001];
void Input()
{
	cin>>n>>k;
	int x,p;
	memset(a,0,sizeof(int)*(k+1));
	for (int i=1;i<=n;i++)
	{
		vec[i].clear();
		cin>>p;
		for (int j=1;j<=p;j++)
		{
			cin>>x;
			a[x]++;
			vec[i].push_back(x);
		}
	}
}
void Process()
{
	Input();
	for (int i=1;i<=k;i++)
		if (a[i]==0)
		{
			cout<<"sad\n";
			return;
		}
	int dem;
	for (int i=1;i<=n;i++)
	{
		dem=0;
		for (int j=0;j<vec[i].size();j++)
			dem+=(a[vec[i][j]]!=1)?1:0;
		if (dem==vec[i].size())
		{
			cout<<"some\n";
			return;
		}
	}
	cout<<"all\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>T;
	while (T--) Process();
	return 0;
}
