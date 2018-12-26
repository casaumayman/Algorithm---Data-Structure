#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000001;
int n,MAXUoc,MAXa,MAXb;
bool UOCa[MAXN],UOCb[MAXN],kta[MAXN],ktb[MAXN];
void Input()
{
	int x;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		kta[x]=true;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		ktb[x]=true;
	}
	UOCa[1]=UOCb[1]=true;
}
void Create()
{
	for (int i=2;i<=1000000;i++)
		for (int j=1;j<=1000000/i;j++)
		{
			if (kta[i*j]) UOCa[i]=true;
			if (ktb[i*j]) UOCb[i]=true;
		}
	for (int i=1000000;i>=1;i--)
		if (UOCa[i] && UOCb[i])
		{
			MAXUoc=i;
			break;
		}
}
void Process()
{
	Input();
	Create();
	for (int i=MAXUoc;i<=1000000;i+=MAXUoc)
	{
		if (kta[i]) MAXa=i;
		if (ktb[i]) MAXb=i;
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    Process();
    cout<<MAXa+MAXb;
    return 0;
}
