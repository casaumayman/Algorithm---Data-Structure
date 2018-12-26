#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
bool kq=true;
void Solve(int i,int j)
{
	if (!kq) return;
	if (a[i]==a[j]+1){
		kq=false;
		return;
	}
	int t=(a[i]-a[j]-1);
	a[i]-=t;
	a[j]+=t;
	if (a[j]>a[j+1])
		if (a[j]==a[j+1]+1) kq=false;
		else Solve(j,j+1);
	if (a[i-1]>a[i])
		if (a[i-1]==a[i]+1) kq=false;
		else Solve(i-1,i);
}
void Process()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=1e9;
	for (int i=n;i>=1;i--)
		if (a[i]<a[i-1]) Solve(i-1,i);
	if (!kq) cout<<"NO";
	else
		for (int i=1;i<=n;i++) cout<<a[i]<<" ";
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

