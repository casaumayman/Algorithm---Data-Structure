#include<bits/stdc++.h>
using namespace std;
int n,t;
bool c[1000000001];
int q[10001];
map <int,int> kq;
void Input()
{
	cin>>t;
	int x;
	for (int i=1;i<=t;i++)
	{
		cin>>x;
		c[x]=true;
		cin>>q[t];
	}
}
int reser(int a)
{
	int zero=0,t,k=0;
	priority_queue <int> heap;
	while (a)
	{
		t=(a%10);
		if (t) heap.push(t);
		else zero++;
		a/=10;
	}
	k=0;
	while (!heap.empty())
	{
		t=heap.top();
		heap.pop();
		k=k*10+t;
	}
	while (zero)
	{
		k*=10;
		zero--;
	}
	return k;
}
void Process(int n)
{
	if (kq[n])
	{
		cout<<kq[n]<<"\n";
		return;
	}
	int buoc=0,t,i=1;
	while (i!=n)
	{
		i++;
		buoc++;
		if (c[i]) kq[i]=buoc;
		while (i%10!=9 && i<n)
		{
			i++;
			buoc++;
			if (c[i]) kq[i]=buoc;
			if (i==n) break;
			t=reser(i+1);
			if (t>n) break;
		}
		t=reser(i);
		if (t>i && t<=n)
		{
			i=t;
			buoc++;
			if (c[i]) kq[i]=buoc;
		}
	}
	cout<<buoc<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Input();
	for (int i=1;i<=t;i++) Process(q[i]);
	//cout<<reser(t);
	return 0;
}
