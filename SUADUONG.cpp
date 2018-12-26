#include<bits/stdc++.h>
using namespace std;
int n,a[100001],l[100001],r[100001];
void Input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	l[0]=0;
	r[n]=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=0) l[i]=l[i-1]+1;
		else l[i]=l[i-1];
	}
	for (int i=n-1;i>=0;i--)
	{
		if (a[i+1]<=0) r[i]=r[i+1]+1;
		else r[i]=r[i+1];
	}
}
void Process()
{
	Input();
	int mins=INT_MAX;
	for (int i=1;i<=n-1;i++)
		mins=min(mins,l[i]+r[i]);
	cout<<mins;
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

