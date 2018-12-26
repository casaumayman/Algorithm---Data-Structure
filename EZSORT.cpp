#include<bits/stdc++.h>
using namespace std;
int n,a[300001];
void Process()
{
	cin>>n;
	int vtn=0,dem=n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==n) vtn=i;
	}
	for (int i=vtn-1;i>=1;i--)
		if (a[i]==dem-1) dem--;
	cout<<--dem;
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

