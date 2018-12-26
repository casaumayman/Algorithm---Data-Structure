#include<bits/stdc++.h>
using namespace std;
int T,n;
void Process()
{
	cin>>n;
	int res=0,x;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		res^=2*x;
	}
	cout<<res<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>T;
	while (T--) Process();
	return 0;
}

