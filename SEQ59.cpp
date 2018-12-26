#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct obj{
	ll a,b;
} a[100001];
ll f[100001];
bool cmp(obj a,obj b)
{
	return (a.a<b.a);
}
bool Find(int i,ll value){
	int d=i+1,c=n,m=(d+c)/2,pos=n+1;
	while (d<=c){
		if (a[m].a*a[i].a>=value){
			pos=m;
			c=m-1;
		}
		else{
			d=m+1;
		}
		m=(d+c)/2;
	}
	if (pos>n) return false;
	if (a[i].b*f[pos]>=value) return true;
	return false;
}
bool check(ll value){
	for (int i=1;i<n;i++){
		if (Find(i,value)) return true;
	}
	return false;
}
void Input(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].a;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i].b;
	}
	sort(a+1,a+n+1,cmp);
	f[n]=a[n].b;
	for (int i=n-1;i>=1;i--) f[i]=max(a[i].b,f[i+1]);
}
void Process(){
	Input();
	ll head=1,tail=1e18,body=(head+tail)/2,res;
	while (head<=tail){
		if (check(body)){
			res=body;
			head=body+1;
		}
		else{
			tail=body-1;
		}
		body=(head+tail)/2;
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

