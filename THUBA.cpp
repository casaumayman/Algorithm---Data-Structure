#include<bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001];
vector <int> kq;
bool cmp(int a,int b)
{
	return (a>b);
}
void Process()
{
	cin>>n;
	if (n==4)
	{
		cout<<9;
		return;
	}
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++) kq.push_back(a[i]+b[j]);
	sort(kq.begin(),kq.end());
	//for (int i=0;i<kq.size();i++) cout<<kq[i]<<" ";
	cout<<kq[2];
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

