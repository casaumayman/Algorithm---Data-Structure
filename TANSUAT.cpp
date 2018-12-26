#include<bits/stdc++.h>
using namespace std;
int n,a[32001];
void Process()
{
	cin>>n;
	int x;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
	}
	for (int i=1;i<=32000;i++)
		if (a[i]>1) cout<<i<<" "<<a[i]<<"\n";
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

