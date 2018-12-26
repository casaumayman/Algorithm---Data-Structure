#include<bits/stdc++.h>
using namespace std;
int dem=1,n,vitri[100001],a[100001];
bool seen[100001];
void update(int l,int r)
{
	for (int i=l;i<=r;i++)
		seen[a[i]]=true;
}
int main()
{
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (i>vitri[a[i]]) vitri[a[i]]=i;
	}
	int i=1,j;
	while (i<n)
	{
		j=vitri[a[i]];
		update(i,j);
		if (j<n) dem++;
		while (seen[a[i]]) i++;
	}
	cout<<dem;
	return 0;
}
