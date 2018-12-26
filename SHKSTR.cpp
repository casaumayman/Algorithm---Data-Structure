#include<bits/stdc++.h>
using namespace std;
int n,Q;
struct query
{
	int r,stt;
	string p;
} q[100001];
string s[100001],kq[100001];
struct Trie
{
	bool ending;
	Trie* a[26];
};
Trie *Create()
{
	Trie* t=new Trie;
	t->ending=false;
	for (int i=0;i<26;i++) t->a[i]=NULL;
	return t;
}
Trie* root=Create();
void Add(string s)
{
	Trie* r=root;
	for (int i=0;i<s.size();i++)
	{
		if (r->a[s[i]-'a']==NULL)
			r->a[s[i]-'a']=Create();
		r=r->a[s[i]-'a'];
	}
	r->ending=true;
}
bool cmp(query a,query b)
{
	if (a.r==b.r) return (a.p.size()<b.p.size());
	return (a.r<b.r);
}
void next(Trie* t,string &s)
{
	Trie *r=t;
	while (1)
	for (int i=0;i<26;i++)
		if (r->a[i]!=NULL)
		{
			s+=i+'a';
			r=r->a[i];
			if (r->ending) return;
			break;
		}
}
string search(string s)
{
	Trie *r=root;
	string k="";
	for (int i=0;i<s.size();i++)
		if (r->a[s[i]-'a']!=NULL)
		{
			k+=s[i];
			r=r->a[s[i]-'a'];
		}
		else
		{
			if (r->ending) return k;
			next(r,k);
			return k;
		}
	if (!r->ending) next(r,k);
	return k;
}
void Input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>s[i];
	cin>>Q;
	for (int i=1;i<=Q;i++)
	{
		cin>>q[i].r>>q[i].p;
		q[i].stt=i;
		if (q[i].r>n) q[i].r=n;
	}
	sort(q+1,q+Q+1,cmp);
}
void Process()
{
	Input();
	int CountIn=0;
	for (int i=1;i<=Q;i++)
	{
		while (CountIn<q[i].r)
		{
			CountIn++;
			Add(s[CountIn]);
		}
		kq[q[i].stt]=search(q[i].p);
	}
	for (int i=1;i<=Q;i++) cout<<kq[i]<<"\n";
	//cout<<(root->a[0]->a[2]==NULL);
//	Trie *r=root;
//	r=r->a[0];
//	for (int i=0;i<26;i++) cout<<((r->a[i]!=NULL)?char(i+'a'):'0')<<" ";
}
int main()
{
 	#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}

