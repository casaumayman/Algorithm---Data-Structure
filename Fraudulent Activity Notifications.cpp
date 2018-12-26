#include<bits/stdc++.h>
using namespace std;
class Trie
{
	private:
		Trie *foot[4];
		int dem;
	public:	
		Trie()
		{
			for (int i=0;i<4;i++) foot[i]=NULL;
			dem=0;
		}
	private:
		bool SEARCH(int x)
		{
			Trie *t=this;
			int ind;
			for (int i=30;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				if (t->foot[ind]==NULL || t->foot[ind]->dem==0) return false;
				t=t->foot[ind];
			}
			return true;
		}
	public:
		void INSERT(int x)
		{
			Trie *t=this;
			int ind;
			for (int i=30;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				if (!t->foot[ind]) t->foot[ind]=new Trie();
				t->foot[ind]->dem++;
				t=t->foot[ind];
			}
		}
		void DELETE(int x)
		{
			if (!SEARCH(x)) return;
			Trie *t=this;
			int ind;
			for (int i=30;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				t->foot[ind]->dem--;
				t=t->foot[ind];
			}
		}
		int KQUERY(int k)
		{
			Trie *t=this;
			int ind,sum=0,tong=0;
			for (int i=30;i>=0;i-=2)
			{
				for (ind=0;ind<4;ind++)
				{
					if (t->foot[ind]!=NULL) sum+=t->foot[ind]->dem;
					if (sum>=k) break;
				}
				tong=(tong<<2)|ind;
				//cout<<sum<<"\n";
				sum-=t->foot[ind]->dem;
				t=t->foot[ind];
			}
			return tong;
		}
};
int a[200001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	int n,d,t,dem=0;
	Trie tree;
	cin>>n>>d;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=d;i++)
	{
		tree.INSERT(a[i]);
	}
	for (int i=d+1;i<=n;i++)
	{
		if (d%2==0)
		{
			t=tree.KQUERY(d/2)+tree.KQUERY(d/2+1);
			if (t<=a[i])
			{
				dem++;
				//cout<<i<<"\n";
			}
			tree.DELETE(a[i-d]);
			tree.INSERT(a[i]);
		}
		else
		{
			t=tree.KQUERY(d/2+1);
			if (t*2<=a[i])
			{
				dem++;
				//cout<<i<<"\n";
			}
			tree.DELETE(a[i-d]);
			tree.INSERT(a[i]);
		}
	}
	cout<<dem;
	return 0;
}

