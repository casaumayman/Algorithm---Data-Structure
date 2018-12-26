#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
void Process()
{
	cin>>n;
	int vtm;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1) vtm=i;
	}
	int dem=vtm,res=0;
	for (int i=vtm;i>=1;i--)
	{
		if (a[i]==dem) dem--;
	}
	res+=dem;
	dem=vtm+1;
	int c=n-(vtm+1)+1;
	for (int i=vtm+1;i<=n;i++)
	{
		if (a[i]==dem) dem++,c--;
	}
	res+=c;
	cout<<res;
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

