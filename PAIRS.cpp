#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001];
map <int,int> m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>n>>k;
	int x,res=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		res+=m[a[i]-k];
		//cout<<a[i]<<" "<<m[a[i]-k]<<"\n";
	}
	cout<<res;
	return 0;
}

