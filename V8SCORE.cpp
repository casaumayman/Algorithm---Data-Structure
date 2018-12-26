#include<bits/stdc++.h>
using namespace std;
int S,K,n,a[21][21],trace[21],tong;
bool kq=false;
void Input()
{
	cin>>S>>K>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=K;j++) cin>>a[i][j];
}
void Output()
{
	kq=true;
	cout<<"YES\n";
	for (int i=1;i<=K;i++) cout<<a[trace[i]][i]<<" ";
}
void submit(int i)
{
	if (i==K+1)
	{
		if (tong==S)
		{
			Output();
			exit(0);
		}
		return;
	}
	for (int j=1;j<=n;j++)
	{
		if (a[j][i]<a[trace[i-1]][i-1] || tong+a[j][i]+(K-i)*a[j][i]>S) continue;
		tong+=a[j][i];
		trace[i]=j;
		submit(i+1);
		tong-=a[j][i];
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Input();
	submit(1);
	if (!kq) cout<<"NO";
	return 0;
}

