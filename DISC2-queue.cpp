#include<bits/stdc++.h>
using namespace std;
struct ele
{
	int id,stt;
	ele(int a,int b)
	{
		id=a;
		stt=b;
	}
};
queue <ele> q;
int n,m,kt[100001];
void Process()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		q.push(ele(i,i));
		kt[i]=i;
	}
	int cs=n,x;
	for (int i=1;i<=m;i++)
	{
		cin>>x;
		kt[x]=++cs;
		q.push(ele(x,cs));
		while (q.front().stt!=kt[q.front().id]) q.pop();
		cout<<q.front().id<<" ";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}

