#include<bits/stdc++.h>
using namespace std;
int n,a[100001],res[100001];
void Process()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=INT_MAX;
	bool hl;
	int kq,coun=0;
	for (int i=n;i>=1;i--)
	{
		hl=true;
		for (int j=n;j>=i+1;j--)
		{
			if (a[j]<a[i])
			{
				hl=false;
				kq=j-i-1;
			}
			if (!hl) break;
		}
		if (hl)
		{
			res[i]=-1;
			coun++;
		}
		else
			res[i]=kq;
	}
	if (coun==n) cout<<-1;
	else
		for (int i=1;i<=n;i++) cout<<res[i]<<" ";
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

