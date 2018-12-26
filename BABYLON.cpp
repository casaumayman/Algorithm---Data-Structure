#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct Rectangular_Block
{
	ll x,y,h;
} RB;
vector <RB> a;
int n;
ll kq[601];
RB Make_RB(ll x,ll y,ll z){
	RB t;
	t.h=z;
	t.x=x;
	t.y=y;
	return t;
}
void TrauSort()
{
	for (int i=0;i<a.size()-1;i++)
		for (int j=i+1;j<a.size();j++)
			if ((a[j].x>a[i].x && a[j].y>a[i].y) || (a[j].y>a[i].x && a[j].x>a[i].y))
				swap(a[i],a[j]);
}
void add(ll x,ll y,ll z){
	a.push_back(Make_RB(x,y,z));
	a.push_back(Make_RB(x,z,y));
	a.push_back(Make_RB(y,z,x));
}
void Process()
{
	TrauSort();
	ll maxs=0;
	for (int i=0;i<a.size();i++)
	{
		kq[i]=a[i].h;
		for (int j=0;j<i;j++)
			if ((a[j].x>a[i].x && a[j].y>a[i].y) || (a[j].y>a[i].x && a[j].x>a[i].y))
				kq[i]=max(kq[i],kq[j]+a[i].h);
		maxs=max(maxs,kq[i]);
	}
	cout<<maxs<<"\n";
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	ll x,y,z;
	while (n)
	{
		for (int i=0;i<n;i++){
			cin>>x>>y>>z;
			add(x,y,z);
		}
		Process();
		a.clear();
		cin>>n;
	}
	return 0;
}

