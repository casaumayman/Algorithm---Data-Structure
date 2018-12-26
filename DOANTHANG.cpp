#include<bits/stdc++.h>
using namespace std;
int a[1000],n,q;
void Input()
{
	cin>>n>>q;
	int x,y;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if (x<-109) x=-109;
		if (x>109) x=109;
		if (y>109) y=109;
		if (y<-109) y=-109;
		a[x+109]++;
		a[y+109]--;
	}
	for (int i=0;i<=1000;i++) a[i]=a[i-1]+a[i];
	int sum=0;
//	for (int i=107;i<=12+109;i++) cout<<i-109<<" "<<a[i]<<"\n";
	for (int i=1;i<=q;i++)
	{
		cin>>x>>y;
		sum=0;
		for (int j=x+109;j<=y+109-1;j++)
			sum+=a[j];
		cout<<sum<<"\n";
	}
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Input();
	return 0;
}

