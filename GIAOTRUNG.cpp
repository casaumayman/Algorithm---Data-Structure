#include<bits/stdc++.h>
using namespace std;
int n,k,c,a[367];
void Input()
{
	cin>>n>>k>>c;
	for (int i=1;i<=c;i++) cin>>a[i];
}
void Process()
{
	Input();
	int i=0,back=0,res=0;
	for (int i=1;i<=n;i++)
	{
		if (binary_search(a+1,a+c+1,i) || i-back==k)
		{
			back=i;
			res++;
		}
	}
	cout<<res;
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

